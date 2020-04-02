#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    vector<int> nums = { 0,1,2,3,4,5,5,6,7,8,9 };
    int num = 5;

    int lower = 0, upper = size(nums) - 1, start = -1, end = -1;

    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (nums[mid] == num) {
            start = mid;
            upper = mid - 1;
        }
        else if (nums[mid] < num) {
            lower = mid + 1;
        }
        else {
            upper = mid - 1;
        }
    }

    lower = 0; upper = size(nums) - 1;
    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (nums[mid] == num) {
            end = mid;
            lower = mid + 1;
        }
        else if (nums[mid] < num) {
            lower = mid + 1;
        }
        else {
            upper = mid - 1;
        }
    }

    cout << "start: " << start << " end: " << end << endl;
    return 0;
}