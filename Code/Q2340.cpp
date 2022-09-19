#include <vector>

using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> min = {0, nums[0]};
        pair<int, int> max = {0, nums[0]};
        for (int i = 0; i < n; i++) {
            if (nums[i] < min.second) min = {i, nums[i]};
            if (nums[i] >= max.second) max = {i, nums[i]}; 
        }
        
        if (min.second >= max.second) {
            // the minimum value and maximum value of the array is the same, 
            // so the array contains only 1 distincy value.
            return 0;
        }
        else if (min.first < max.first) {
            // just move them to the left\right side.
            return min.first + n-1 - max.first;
        }
        else {
            return min.first + n-2 - max.first;
        }
    }
};