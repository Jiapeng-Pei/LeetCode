#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int n = 0;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        n = nums.size();
        if (n < 4) return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3;) {
            threeSum(nums, ret, i+1, target - nums[i]);
            moveForward(nums, i);
        }

        return ret;
    }

    void threeSum(vector<int>& nums, vector<vector<int>>& ret, int start, long long target) {
        for (int i = start; i < n - 2;) {
            long long subTarget = target - (long)nums[i];
            signed left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] < subTarget) {
                    moveForward(nums, left);
                }
                else if (nums[left] + nums[right] > subTarget) {
                    moveBackward(nums, right);
                }
                else {
                    ret.push_back(vector<int>{nums[start - 1], nums[i], nums[left], nums[right]});
                    moveForward(nums, left);
                    moveBackward(nums, right);
                }
            }

            moveForward(nums, i);
        }
    }

    inline void moveForward(vector<int>& nums, signed& index) {
        index++;
        while (index < n && nums[index] == nums[index-1]) index++;
    }

    inline void moveBackward(vector<int>& nums, signed& index) {
        index--;
        while (index >= 0 && nums[index] == nums[index+1]) index--;
    }   
};