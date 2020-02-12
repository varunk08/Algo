#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

 int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto& num : nums) {
            auto it = counts.find(num);
            if(it == counts.end()) {
                counts.emplace(num, 1);
            } else {
                (it->second)++;
            }
        }
        
        unsigned max = 0;
        int number = 0;
        for (const auto& elem : counts) {
            if (elem.second > max) {
               max = elem.second;
                number = elem.first;
            }            
        }
        return number;
    }

int main(){
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

  cout << majorityElement(nums) << endl;
  return 0;
}
