#include <stdio.h>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        findPermutations(ret, nums, 0);

        return ret;
    }

    void findPermutations(vector<vector<int>>& ret, vector<int>& nums, int begin) {
        if (begin == nums.size() - 1) {
            ret.push_back(nums);
            return;
        }        

        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            findPermutations(ret, nums, begin + 1);
            swap(nums[begin], nums[i]);
        }
    }
};