#include <iostream>
#include <bitset>


using namespace std;

unsigned long Add(unsigned long a, unsigned long b)
{
  unsigned long sum = 0, carryIn = 0, tempA = a, tempB = b, k = 1;
  
  while (tempA || tempB) {
    unsigned long ak = a & k, bk = b & k;
    unsigned long carryOut = (ak & bk) | (ak & carryIn) | (bk & carryIn);
    sum |= (ak ^ bk ^ carryIn);

    tempA >>=1; tempB >>=1;
    carryIn = carryOut << 1;
    k = k << 1;
  }

  return sum | carryIn;
}

unsigned long Multiply(unsigned long x, unsigned long y)
{
  unsigned long sum = 0;
  while (x) {
    if (x & 1) {
       sum = Add(sum, y);
    }
    x >>= 1; y <<= 1;
  }

  return sum;
}

int main()
{
  cout << "Adding without arithmetic" << endl;
  unsigned long x = 15;
  unsigned long y = 2;
  cout << x << " x " << y << " = " << Multiply(x,y) << endl;
  return 0;
}
