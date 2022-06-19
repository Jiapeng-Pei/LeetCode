#include <vector>

using namespace std;    

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (right && nums[right] == nums[0]) right--;
        while (nums[left] > nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};