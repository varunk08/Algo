#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

long SwapBits(long num, int i, int j)
{
    long res = num;
    if (((num >> i) & 1) != ((num >> j) & 1)) {
        res = num ^ ((1 << i) | (1 << j));
    }

    return res;
}

int main(int argc, char** argv)
{
    long num = 0b000001010;
    cout << "Before: " << bitset<8>(num) << endl;
    cout << bitset<8>(SwapBits(num, 1, 7)) << endl;
    return 0;
}