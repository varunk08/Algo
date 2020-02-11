#include <iostream>

using namespace std;

double Power(double x, int y)
{
  double result = 1;
  int power = y;

  if (power < 0) {
    power = -power;
    x = 1.0 / x;
  }

  while (power) {
    
    if (power & 1) {
      result *= x;
    }

    x = x * x;
    power >>= 1;
  }
  
  return result;
}

int main()
{
  cout << "Calculates x power y (x^y)." << endl;
  double x = 5.0;
  int y = 3;
  cout << x << "^" << y << " = " << Power(x, y) << endl;
  return 0;
}
