#include <stdio.h>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() == 0) return ret;
        findPermutations(nums, ret, 0);
        return ret;
    }

private:
    void findPermutations(vector<int>& nums, vector<vector<int>>& ret, int begin) {
        if (begin == nums.size() - 1) {
            ret.push_back(nums);
            return;
        }
        
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            findPermutations(nums, ret, begin + 1);
            swap(nums[begin], nums[i]);
        }
    }
};