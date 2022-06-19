#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> numbers;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        recursive(candidates, 0, target);

        return ret;
    }

    void recursive(vector<int>& candidates, int index, int target) {
        if (target == 0) {
            ret.push_back(numbers);
            return;
        }

        for (int i = index; i < candidates.size();) {
            int cur = candidates[i];
            if (cur <= target) {
                numbers.push_back(cur);
                recursive(candidates, i + 1, target - cur);
                numbers.pop_back();
            }
            do {
                i++;
            } while (i < candidates.size() && candidates[i] == candidates[i-1]);
        }
    }
};