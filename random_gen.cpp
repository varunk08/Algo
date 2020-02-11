#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int ZeroOneRandom() {
  return rand() % 2;
}

int main()
{
  srand(time(nullptr));

  int result;
  int a = 1;
  int b = 6;
  int num_possible = b - a + 1;
  do {
    result = 0;
    for (int i = 0; (1 << i) < num_possible; i++) {
      result = (result << 1) | ZeroOneRandom();
    }
  } while (result >= num_possible);
  result += a;
  // Complexity: O(log(b-a+1));
  cout << "(" << a << ", " << b << "): " << result << endl;
  
  return 0;
}
