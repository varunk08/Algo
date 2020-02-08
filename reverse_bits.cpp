#include <iostream>
#include <bitset>

using namespace std;

uint32_t reverse_bits(uint32_t x)
{
    uint32_t i = 0;
    uint32_t j = 31;
    uint32_t res = x;
    while (i < j){
        if (((x >> i) & 1) != ((x >> j) & 1)) {
            res ^= ((1 << i) | (1 << j));
        }
        i++; j--;
    }

    return res;
}

int main(int argc, char** argv)
{
    uint32_t input_num = 0b10101111;
    cout << bitset<32>(input_num) << endl;
    cout << bitset<32>(reverse_bits(input_num)) << endl;
    return 0;
}