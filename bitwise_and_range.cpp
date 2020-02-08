/*Given a range[m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.*/

#include <iostream>
#include <bitset>

using namespace std;

int rangeBitwiseAndBrute(int m, int n)
{
    int res = m;
    m++;
    while (m <= n) {
        res &= m;
        m++;
    }
    return res;
}

int rangeBitwiseAnd(int m, int n)
{
    // x & (x-1): unsets the last set bit. 101 & 100: 100
    // x & ~(x-1): isolates the last set bit. 101 & 011: 001
    uint32_t ctr = m;
    int res = 0;

    while (ctr) {
        uint32_t lastSet = ctr & ~(ctr - 1);

        uint32_t cur = m;
        while (cur <= n) {
            if (cur & lastSet) {
                res |= lastSet;
                cur++;
            }
            else {
                res &= ~lastSet;
                break;
            }
        }
        ctr = ctr & (ctr - 1);
    }

    return res;
}

int main()
{
     int m = 5; // 101 6:110
     int n = 2147483647; // 111

     cout << (rangeBitwiseAnd(m, n)) << endl;

    return 0;
}