#include <vector>
#include <stdio.h>

using namespace::std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> subset;

    vector<vector<int>> subsets(vector<int>& nums) {
        ret.push_back(subset);
        if (!nums.size()) return ret;

        for (int i = 1; i <= nums.size(); i++) {
            findSubsets(nums, i, 0);
        }

        return ret;
    }

    void findSubsets(vector<int>& nums, int remain, int pos) {
        if (remain == 0) {
            ret.push_back(subset);
            return;
        }

        for (int i = pos; i < nums.size(); i++) {
            if (remain > nums.size() - pos) break;
            subset.push_back(nums[i]);
            findSubsets(nums, remain - 1, i + 1);
            subset.pop_back();
        }        
    }
};