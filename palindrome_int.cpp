#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPalindrome(int x) {
  if (x <= 0) {
    return x == 0;
  }

  int num_digits = static_cast<int>(floor(log10(x))) + 1;
  int msd_mask   = static_cast<int>(pow(10, num_digits - 1));

  for (int i = 0; i < num_digits / 2; i++) {
    if ((x / msd_mask) != (x % 10)) {
      return false;
    }

    x %= msd_mask;
    x /= 10;
    msd_mask /= 100;
  }
  return true;  
}
int main()
{
  int x = 1000021;
  cout << x << ": " << IsPalindrome(x) << endl;
  return 0;
}
