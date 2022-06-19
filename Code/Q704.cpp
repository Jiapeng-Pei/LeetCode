#include <stdio.h>
#include <vector>

using namespace::std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0 || target < nums[0] || target > nums[nums.size() - 1])
            return -1;
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
        if (nums[left] == target)
            return left;
        else 
            return -1;
    }
};