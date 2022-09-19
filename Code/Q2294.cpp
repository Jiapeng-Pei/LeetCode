#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 1, n = nums.size();
        int minVal = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] - minVal > k) {
                ret++;
                minVal = nums[i];
            }
        }
        
        return ret;
    }
};