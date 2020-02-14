#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dutch_flag_partition(int pivot_index, vector<int>* pVector) {
  vector<int>& A = *pVector;
  int pivot = A[pivot_index];
  int smaller = 0, equal = 0, larger = size(A);
  
  while (equal < larger) {
    if (A[equal] < pivot) {
      swap(A[smaller++], A[equal++]);
    }
    else if (A[equal] == pivot) {
      equal++;
    }
    else {
      swap(A[equal], A[--larger]);
    }
  }
}

int main(){
  vector<int> input_vector = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3 };
  dutch_flag_partition(1, &input_vector);
  for (auto& i : input_vector) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
