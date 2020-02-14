#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void increment_int(vector<int>* pVec) {
  vector<int>& A = *pVec;

  int carry = 1;
  int i = size(A) - 1;
  while (carry) {
    if (i < 0) {
        vector<int> temp(size(A));
        temp.assign(A.cbegin(), A.cend());
        A.resize(size(temp) + 1);
        A[0] = carry;
        for (int i = 0; i < size(temp); i++) {
            A[i + 1] = temp[i];
        }
        break;
    }

    int new_val = A[i] + carry;
    carry = new_val / 10;
    A[i] = new_val % 10;
    i--;
  }

}
int main()
{
  vector<int> input_num = { 9, 9, 9, 9}; // result= 124
  increment_int(&input_num);
  for (auto i : input_num) {
    cout << i << " ";
  }
  return 0;
}
