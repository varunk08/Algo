#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void PermuteCombo(set<vector<int>>& allCombos, vector<int>& curCombo, int curSum, vector<int>& candidates, int target) {
    if (curSum == target) {
        vector<int> res = curCombo;
        sort(res.begin(), res.end());
        allCombos.insert(res);
        return;
    }
    else if (curSum > target) {
        return;
    }

    for (int i = 0; i < candidates.size(); i++) {
        curCombo.push_back(candidates[i]);
        PermuteCombo(allCombos, curCombo, curSum + candidates[i], candidates, target);
        curCombo.pop_back();
    }
}

int main() 
{
    vector<int> candidates = { 2, 3, 5 };
    int target = 8;
    vector<int> curCombo;
    set<vector<int>> allCombos;
    PermuteCombo(allCombos, curCombo, 0, candidates, target);

    vector<vector<int>> result;
    for (auto vec : allCombos) {
        result.push_back(vec);
    }

    for (auto vec : allCombos) {
        for (auto i : vec) {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}