#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> input =
  {
   {1, 2, 3, },
   {5, 6, 7, },
   {9, 10, 11,}

  };


int main() {
  vector<vector<int>> shift =
    {
     // row, column
     {0,1}, {1, 0}, {0, -1}, {-1, 0}
    };

  vector<int> spiralOrder;
  int row = 0;
  int col = 0;
  int nextRow =  0;
  int nextCol = 0;
  int dir = 0;
  
  // Assume square matrix.
  for (int i = 0; i < size(input) * size(input[0]); i++ ) {
    cout << row << ", " << col << endl;
    spiralOrder.emplace_back(input[row][col]);
    input[row][col] = -1;

    nextRow = row + shift[dir][0];
    nextCol = col + shift[dir][1];

    if (nextRow < 0 || nextRow >= size(input) || nextCol < 0  || nextCol >= size(input[0]) ||
        input[nextRow][nextCol] == -1) {
      dir = (dir + 1) % 4;
      nextRow = row + shift[dir][0];
      nextCol = col + shift[dir][1];
    }
    
    row = nextRow;
    col = nextCol;
  }

  for (auto i : spiralOrder) {
    cout << i << ", " ;
  }
  cout << endl;
    
  return 0;
}
