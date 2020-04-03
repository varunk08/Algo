#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int furthest = 0;
    int min_jumps = 0;
    //vector<int> nums = { 2,3,1,1,4 };
    vector<int> nums  = { 7,0,9,6,9,6,1,7,9,0,1,2,9,0,3 };

    int prev_furthest = 0;
    for (int i = 0; i <= furthest && prev_furthest < size(nums) - 1; i++) {
        if (i > prev_furthest) {
            min_jumps++;
            prev_furthest = furthest;
        }

        if (nums[i] + i > furthest) {
            furthest = nums[i] + i;
        }
    }

    cout << "Min Jumps: " << min_jumps << endl;

    return 0;
}