#include <iostream>
#include <vector>

using namespace std;

void increment_int(vector<int>* pVec) {
  vector<int>& A = *pVec;

  int carry = 1;
  int i = size(A) - 1;
  while (carry) {
    int new_val = A[i] + carry;
    carry = new_val / 10;
    A[i] = new_val % 10;
    i--;
  }

}
int main()
{
  vector<int> input_num = { 1, 9, 9}; // result= 124
  increment_int(&input_num);
  for (auto i : input_num) {
    cout << i << " ";
  }
  return 0;
}
