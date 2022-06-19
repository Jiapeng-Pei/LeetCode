#include <stdio.h>
#include <vector>

using namespace ::std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        if (nums.size() == 0 || target < nums.front() || target > nums.back())
            return ret;
        int left = binary_search(nums, target);
        if (nums[left] != target)
            return ret;
        ret[0] = left;
        int right = binary_search(nums, target + 1);
        if (nums[right] == target) {
            ret[1] = right;
        }
        else {
            ret[1] = right - 1;
        }
        return ret;
    }

    int binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};