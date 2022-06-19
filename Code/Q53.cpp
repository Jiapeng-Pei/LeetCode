// first, i can't use silding window to solve this problem.
// for O(n) time complexity and dynamic programming, O(n) denotes 
// the largest subarray ending at position n.
// state[n] initial value: nums[n]
// state[n] = max(state[n-1] + state[n], state[n])
// state[0] = state[0];
// 可以观察出，这道问题并没有对字串进行及其严格的限制。只是要找字串
// 中之和的最大值，并不清楚什么时候要扩大/收缩窗口。
#include <stdio.h>
#include <vector>
#include <climits>

using namespace::std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int ret = nums[0];
        if (nums.size() == 1) return ret;
        vector<int> state(nums.size(), 0);
        state[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            state[i] = max(nums[i], state[i-1] + nums[i]);
            ret = max(ret, state[i]);
        }

        return ret;
    }
};