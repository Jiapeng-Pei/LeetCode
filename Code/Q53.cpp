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
        int maxSubarray = INT_MIN;
        int curSubarray = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSubarray += nums[i];
            maxSubarray = max(maxSubarray, curSubarray);
            curSubarray = curSubarray < 0 ? 0 : curSubarray;
        }

        return maxSubarray;
    }
};