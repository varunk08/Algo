#include <iostream>
#include <bitset>

using namespace std;

int hamming_weight(uint32_t n)
{
    uint32_t x = n;
    int count = 0;

    while (x) {
        count += (x & 1);
        x >>= 1; 
    }

    return count;
}

int main()
{
    cout << "Returns the number of set bits." << endl;
    uint32_t n = 0b100001111;
    cout << bitset<32>(n) << endl;
    cout << (hamming_weight(n)) << endl;
    return 0;
}