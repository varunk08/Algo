#include <iostream>
#include <bitset>

using namespace std;

unsigned long closest_int_same_bit_count(unsigned long x)
{
    const static int NumUnsignedBits = 64;
    for (int i = 0; i < NumUnsignedBits - 1; i++) {
        if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
            x = x ^ (1UL << i) | (1UL << (i + 1));
            return x;
        }
    }
}

int main()
{
    // Find the closest integer with the same weight.
    // Solution is to flip two rightmost bits that differ from each other.
    int input_num = 7; // 7-> 11

    cout << bitset<64>(input_num) << ":  " << bitset<64>(closest_int_same_bit_count(input_num)) << endl;

    return 0;
}