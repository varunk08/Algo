#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n = 8;
  vector<vector<int>> triangle;

  for (int i = 0; i < n; i++) {
    vector<int> currentRow;
    for (int j = 0; j <= i; j++) {
      currentRow.emplace_back(j > 0 && j < i ? triangle.back()[j-1] + triangle.back()[j] : 1);
    }
    triangle.push_back(currentRow);
  }

  int i = 0;
  for (auto vec : triangle) {
    for (int spaceCnt = 0; spaceCnt < (n - i) / 2; spaceCnt++) {
      cout << "  ";
    }
    for (auto i : vec) {
      cout << i << " ";
    }
    i++;
    cout << endl;
  }

  return 0;
}
