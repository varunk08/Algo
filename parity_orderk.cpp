#include <iostream>
#include <vector>

using namespace std;

unsigned int ComputeParity(unsigned long x)
{
  unsigned int result = 0;

  while (x) {
    result ^= 1;
    x = x & (x-1); // Set the last bit to 0.
  }

  return result;
}

int main(int argc, char** argv)
{
  vector<unsigned long> nums =
    {
     0b000100,
     0b000101,
     0b000110,
     0b000111
    };
  for (auto& x : nums) {
    cout << endl;
    cout << "Input: " << x << endl;
    cout << "Parity: " << ComputeParity(x) << endl;
  }
  return 0;
}
