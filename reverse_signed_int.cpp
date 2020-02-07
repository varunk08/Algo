#include <algorithm>
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int reverse(int x)
{
    if (x <= std::numeric_limits<int>::min() ||
        x >= std::numeric_limits<int>::max())
    {
        return 0;
    }

    int sign = (x < 0) ? - 1 : 1;
    long long res = 0;
    long long num = static_cast<long long>(x) * sign;
    while (num) {
        res = (num % 10) + (res * 10);
        num /= 10;
    }

    res *= sign;

    return (res > std::numeric_limits<int>::max() ||
            res < std::numeric_limits<int>::min()  ) ? 0 : res;
}

int main(int argc, char** argv)
{
    int num = -1220;
    int longNum = 1534236469;
    long int num2 = -2147483648;
    cout << num2 << endl << reverse(num2) << endl;
    return 0;
}
