#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> nums = {1,1}; //{0,1,1,2,2,3,4,4,5,6,7};
  
  int valid = 0;
  for (int i = 1; i < size(nums); i++) {
    while(nums[valid] == nums[i]) {
      i++;

      if (i == size(nums)) {
          break;
      }
    }
    
    if (i < size(nums)) {
        nums[++valid] = nums[i];
    }
    else {
        break;
    }

  }

  for (auto i : nums) {
    cout << i << ", ";
  }
  cout << endl << valid + 1 << endl;


  return 0;
}
