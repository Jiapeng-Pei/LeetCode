#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace ::std;

class Solution {
public:
    inline void moveToNext(const vector<int>& nums, int& index, bool forward) {
        int next = 0;
        if (forward) {
            next = index + 1;
            while (next < nums.size() && nums[next] == nums[index]) next++;
        }
        else {
            next = index - 1;
            while (next >= 0 && nums[next] == nums[index]) next--;
        }
        index = next;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() <= 2) return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2;) {
            int j = i + 1, k = nums.size() - 1;
            int cur = nums[i] + nums[j] + nums[k];
            while (j < k) {
                if (cur > 0) {
                    moveToNext(nums, k, false);
                } 
                else if (cur < 0) {
                    moveToNext(nums, j, true);
                } 
                else {
                    ret.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    moveToNext(nums, k, false);
                    moveToNext(nums, j, true);
                }
            }

            moveToNext(nums, i, true);            
        }

        return ret;
    }
};