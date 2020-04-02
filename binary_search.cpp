#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {

    vector<int> nums = { 0,1,2,3,4,5,6,7,8,9 };
    int num = 5;
    for (int i = 0; i < size(nums); i++) { cout << i << "-> " << nums[i] << endl; }
    int lower = 0;
    int upper = size(nums);

    while (upper > lower) {
        int mid = lower + (upper - lower) / 2;

        if (nums[mid] == num) {
            cout << "found at: " << mid << endl;
            break;
        }
        else if (nums[mid] < num) {
            lower = mid + 1;
        }
        else {
            upper = mid;
        }
    }

    return 0;
}