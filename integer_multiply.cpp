#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> multiply(vector<int>& first, vector<int>& second) {
  vector<int> result(size(first) + size(second), 0);
  first.front() = abs(first.front());
  second.front() = abs(second.front());
  
  int sign = (first[0] < 0) ^ (second[0] < 0) ? -1 : 1;
  
  for (int i = size(first) - 1; i >= 0; i--) {
    for (int j = size(second) - 1; j >= 0; j--) {
      result[i + j + 1] = result[i + j + 1] + first[i] * second[j];
      result[i + j]     += result[i + j + 1] / 10;
      result[i + j + 1] = result[i + j + 1] % 10;
    }
  }

  // Remote zeroes in the front.
  result = {
            find_if_not(begin(result), end(result), [](int a) { return a ==0; }),
            end(result)
  };

  if (empty(result)) {
    result = {0};
  }
  
  result[0] *= sign;
  return result;
}

int main()
{
  vector<int> first_num = { 2, 5, 0};
  vector<int> second_num = { 1,0,0 };

  vector<int> result = multiply(first_num, second_num);
  for (auto i : result) {
    cout << i;
  }

  return 0;
}
