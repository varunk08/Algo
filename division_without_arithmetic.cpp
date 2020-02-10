#include <iostream>

using namespace std;

int Divide(int x, int y)
{
  int result = 0;
  int power = 32;

  unsigned long long yPower = static_cast<unsigned long long>(y) << power;

  while (x >= y){
    while (yPower > x) {
      yPower >>= 1;
      power--;
    }
    result += 1 << power;
    x -= yPower;
  }

  return result;
}

int main()
{
  int x = 22;
  int y = 5;
  cout << x << "/" << y << "=" << Divide(x, y) << endl;
  return 0;
}
