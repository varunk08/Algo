#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<vector<int>> image = {
                               {1,2,3,4,},
                               {5,6,7,8,},
                               {9,10,11,12},
                               {13,14,15,16}
  };

  for (auto vec : image) {
    for (auto i : vec) {
      cout << i << ", ";
    }
    cout << endl;
  }


  const int ArraySize = size(image);
  const int LastIdx = ArraySize - 1;

  for (unsigned i = 0; i < ArraySize / 2; i++) {
    for (unsigned j = i; j < LastIdx - i; j++) {
      int leftCol  = image[LastIdx - j][i];
      int botRow   = image[LastIdx - i][LastIdx - j];
      int rightCol = image[j][LastIdx - i];
      int topRow   = image[i][j];

      image[i][j] = leftCol;
      image[j][LastIdx - i] = topRow;
      image[LastIdx - i][LastIdx - j] = rightCol;
      image[LastIdx - j][i] = botRow;
    }
  }

  cout << endl;
  for (auto vec : image) {
    for (auto i : vec) {
      cout << i << ", ";
    }
    cout << endl;
  }
  
  return 0;
}
