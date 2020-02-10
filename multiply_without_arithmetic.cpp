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
  while (x) { //0b1111 > 0b0111 > 0b0011 > 0b0001 > 0b0000
    if (x & 1) {
       sum = Add(sum, y);
    }
    x >>= 1; y <<= 1; // 0b0010 > 0b00100 > 0b001000 > 0b0010000
  }

  return sum;
}

int main()
{
  cout << "Adding without arithmetic" << endl;
  unsigned long x = 15; // 0b1111
  unsigned long y = 2;  // 0b0010
  cout << x << " x " << y << " = " << Multiply(x,y) << endl;
  return 0;
}
