#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace::std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> curVec;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0 || target <= 0) return ret;
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, 0, target);
        return ret;
    }

private:
    void findCombination(vector<int>& candidates, int pos, int rest) {
        if (rest == 0) {
            ret.push_back(curVec);
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            if (rest < candidates[i]) break;

            curVec.push_back(candidates[i]);
            findCombination(candidates, i, rest - candidates[i]);
            curVec.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates{2, 3, 5};
    int target = 8;
    vector<vector<int>> ret = s.combinationSum(candidates, target);
    for (vector<int> v : ret) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}