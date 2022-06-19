#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        findPermutations(nums, ret, 0);

        return ret;
    }

private:
    void findPermutations(vector<int>& nums, vector<vector<int>>& ret, int begin) {
        if (begin == nums.size() - 1) {
            ret.push_back(nums);
            return;
        }
        
        unordered_set<int> set;
        for (int i = begin; i < nums.size(); i++) {
            if (set.count(nums[i])) continue;
            swap(nums[begin], nums[i]);
            findPermutations(nums, ret, begin + 1);
            swap(nums[begin], nums[i]);
            set.insert(nums[i]);
        }
    }
};