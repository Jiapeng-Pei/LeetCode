#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, ret = INT_MAX;
        while (right < nums.size()) {
            // 不满足条件时扩大窗口
            sum += nums[right++];
            // 满足条件时缩小窗口
            while (left < right && sum >= target) {
                ret = min(ret, right - left);
                sum -= nums[left++];
            }
        }

        return ret == INT_MAX ? 0 : ret;
    }
};