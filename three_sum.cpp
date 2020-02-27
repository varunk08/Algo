#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };

    vector<vector<int>> result;

    for (int i = 0; i < size(nums); i++) {
        for (int j = i + 1; j < size(nums); j++) {
            for (int k = j + 1; k < size(nums); k++) {
                if ((nums[i] + nums[j] + nums[k]) == 0) {
                    result.emplace_back(vector<int>{ nums[i], nums[j], nums[k] });

                }
            }
        }
    }

    for (auto vec : result) {
        for (auto i : vec) {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}