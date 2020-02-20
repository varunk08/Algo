#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> A = { 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 1; i < size(A); i++) {
    if (((i % 2) && (A[i-1] > A[i])) || ( !(i % 2) && (A[i-1] < A [i])) ) {
      swap(A[i-1],  A[i]);
    }
  }

  for (auto i : A) {
    cout << i;
  }
  return 0;
}
