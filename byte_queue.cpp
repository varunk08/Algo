#include <iostream>
#include <vector>
#include <stdio.h>

constexpr unsigned BufferSize = 2048;
constexpr unsigned NumBlocks = 64;
constexpr unsigned BufferInitCode = 0x3;
constexpr uint16_t InvalidHandle = 0xFF;

unsigned char data[BufferSize];

union BlockInfo {
    struct {
        uint16_t free     : 1; // is this block free
        uint16_t count    : 6; // number of elements stored in this block
        uint16_t has_next : 1; // true if the block has elements in next block
        uint16_t next     : 6; // next block used by this queue
        uint16_t res      : 2; // reserved bits, used to check buffer init
    };
    uint16_t u16All;
};

unsigned BlockTableBytes = NumBlocks * sizeof(BlockInfo);
constexpr unsigned BlockSizeBytes = (BufferSize - NumBlocks * sizeof(BlockInfo)) / NumBlocks;

using queue_handle = uint16_t; // queue handle is just the block number.

void on_out_of_memory() {
    std::cout<< "Out of memory!" << std::endl;
}

void on_illegal_operation() {
    std::cout << "Illegal operation performed!" << std::endl;
}

queue_handle create_queue() {

    BlockInfo* pInfo = reinterpret_cast<BlockInfo*>(data);

    // This is the first time a queue is created, so set up the block table.
    if (pInfo[0].u16All == 0) {
        BlockInfo initInfo = {};
        initInfo.u16All    = 0;
        initInfo.free      = 1;
        initInfo.res       = BufferInitCode;

        for (int i = 0; i < NumBlocks; i++) {
            pInfo[i] = initInfo;
        }
    }

    queue_handle handle = InvalidHandle;
    bool found = false;
    for (int i = 0; i < NumBlocks; i++) {
        if (pInfo[i].free) {
            pInfo[i].free = 0;
            handle        = i;
            found         = true;
            break;
        }
    }

    if (found == false) {
        on_out_of_memory();
    }

    return handle;
}

void destroy_queue(queue_handle block) {
    if (block >= NumBlocks) {
        on_illegal_operation();
        return;
    }

    BlockInfo* pInfo = reinterpret_cast<BlockInfo*>(data);
    if (pInfo[block].free) {
        // attempt to destory an free block.
        on_illegal_operation();
        return;
    }
    if (pInfo[block].has_next) {
        destroy_queue(pInfo[block].next);
    }

    pInfo[block].u16All = 0;
    pInfo[block].res    = BufferInitCode;
    pInfo[block].free   = 1;
}

void enqueue_byte(queue_handle block, unsigned char b) {

    if (block >= NumBlocks) {
        on_illegal_operation();
        return;
    }

    BlockInfo* pInfo = reinterpret_cast<BlockInfo*>(data);
    if (pInfo[block].count < BlockSizeBytes) {
        // This block can fit the new element
        unsigned char* pCurBlock      = data + BlockTableBytes + BlockSizeBytes * static_cast<size_t>(block);
        pCurBlock[pInfo[block].count] = b;
        pInfo[block].count++;
    }
    else {
        if (pInfo[block].has_next) {
            return enqueue_byte(pInfo[block].next, b);
        }

        // The block is full, so allocate a new block
        bool found = false;
        for (int i = 0; i < NumBlocks; i++) {
            if (pInfo[i].free) {
                pInfo[i].free            = 0;
                pInfo[i].count           = 1;
                unsigned char* pCurBlock = data + BlockTableBytes + BlockSizeBytes * static_cast<size_t>(i);
                pCurBlock[0]             = b;
                pInfo[block].next        = i;
                pInfo[block].has_next    = 1;
                found                    = true;
                break;
            }
        }

        if (found == false) {
            on_out_of_memory();
        }
    }
}

unsigned char dequeue_byte(queue_handle block) {
    unsigned char result = '0';
    if (block >= NumBlocks) {
        on_illegal_operation();
        return result;
    }

    BlockInfo* pInfo = reinterpret_cast<BlockInfo*>(data);
    if (pInfo[block].count == 0) {
        on_illegal_operation();
        return result;
    } else {
        unsigned char* pCurBlock = data + BlockTableBytes + BlockSizeBytes * static_cast<size_t>(block);
        result = pCurBlock[0];

        if (pInfo[block].count == 1) {
            // the parent block is allowed to be with zero elements.
            pInfo[block].count--;
        }
        else {
            bool not_done = true;
            unsigned char* pDst = &pCurBlock[0];
            unsigned char* pSrc = &pCurBlock[1];
            BlockInfo* pCurInfo = &pInfo[block];
            BlockInfo* pPrevInfo = nullptr;
            int i = 0;
            while (not_done) {
                *pDst++ = *pSrc++;
                i++;
                if (i == pCurInfo->count-1) {
                    if (i >= BlockSizeBytes-1 && pCurInfo->count == BlockSizeBytes && pCurInfo->has_next) {
                        // do not decrement the count because the child block will have atleast one element
                        queue_handle child = pCurInfo->next;
                        pPrevInfo          = pCurInfo;
                        pCurInfo           = &pInfo[child];
                        pCurBlock          = data + BlockTableBytes + BlockSizeBytes * static_cast<size_t>(child);
                        pSrc               = &pCurBlock[0];
                    }
                    else {
                        // the block doesn't have next
                        pCurInfo->count--;
                        if (pCurInfo->count == 0) {
                            // Recycle the block. This is a child block, because if the parent block
                            // had only 1 element, it is handled above.
                            pCurInfo->has_next = 0;
                            pCurInfo->free = 1;

                            if (pPrevInfo != nullptr) {
                                pPrevInfo->has_next = 0;
                            }
                        }
                        not_done = false;
                    }
                }
                else if (i == BlockSizeBytes) {
                    // we have allowed i to go past the last element, we must move pDst to the child block
                    pDst = &pCurBlock[0];

                    // pDst is techically at the -1 index for the child block.
                    i    = -1;
                }
            }            
        }
    }

    return result;
}

int main() {
    memset(data, 0, sizeof(data));
    /*queue_handle t0 = create_queue();
    for (int i = 0; i < 1024; i++) {
        enqueue_byte(t0, i);
    }
    for (int j = 0; j < 1024; j++) {
        std::cout << static_cast<unsigned>(dequeue_byte(t0)) << std::endl;
    }
    destroy_queue(t0);

    
    for (int i = 0; i < 10; i++) {
        create_queue();
        enqueue_byte(i, 'a');
        std::cout << dequeue_byte(i) << std::endl;
        destroy_queue(i);
    }*/

    std::cout << std::endl;

    // Given test case.
    queue_handle q0 = create_queue();
    enqueue_byte(q0, 0);
    enqueue_byte(q0, 1);
    queue_handle q1 = create_queue();
    enqueue_byte(q1, 3);
    enqueue_byte(q0, 2);
    enqueue_byte(q1, 4);
    printf("%d" , dequeue_byte(q0));
    printf("%d\n" , dequeue_byte(q0));
    enqueue_byte(q0, 5);
    enqueue_byte(q1, 6);
    printf("%d", dequeue_byte(q0));
    printf("%d\n", dequeue_byte(q0));
    destroy_queue(q0);
    printf("%d", dequeue_byte(q1));
    printf("%d", dequeue_byte(q1));
    printf("%d\n", dequeue_byte(q1));
    destroy_queue(q1);

    return 0;
}