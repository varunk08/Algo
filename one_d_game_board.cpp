#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> board = { 3,3,1,0,2,0,1};

  int lastIndex = size(board) - 1;
  int furthestSoFar = 0;

  for (int i = 0; i <= furthestSoFar && furthestSoFar < lastIndex; i++) {
    furthestSoFar = max(furthestSoFar, i + board[i]);
  }

  bool canWin = furthestSoFar >= lastIndex;

  if (canWin) {
    cout << "Can win" << endl;
  } else {
    cout << "Cannot win" << endl;
  }
  
  return 0;
}
