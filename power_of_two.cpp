#include <iostream>
#include <bitset>

using namespace std;

bool isPowerOfTwo(int n) {
    return (n <= 0) ? false : ((n & (n - 1)) == 0); // Signed integer overflow!
}

int main()
{
    for (int i = 0; i < 33; i++) {
        cout << i << " " << isPowerOfTwo(i) << endl;
    }
    return 0;
}