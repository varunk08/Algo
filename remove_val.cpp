#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> nums = {4,4,4,5};// { 1, 2, 3, 4, 4, 5, 5, 6, 7};
  int val = 4;

  int garb = size(nums) - 1;

  int i = 0, valid = 0;
  for (i = 0; i < size(nums) && garb >= i; i++) {
    if (nums[i] == val) {
      while (nums[garb] == val && garb > i) {
        garb--;
      }

      if (garb == i) {
        break;
      }
      
      swap(nums[i], nums[garb--]);
      valid++;
    }
    else {
        valid++;
    }
  }

  cout << "length = " << valid << endl;
  return 0;
}
