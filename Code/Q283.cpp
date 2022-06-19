#include <stdio.h>
#include <vector>

using namespace::std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // for (int i = nums.size() - 1; i >= 0; i--) {
        //     if (nums[i]) continue;
        //     for (int k = i + 1; k < nums.size() && nums[k]; k++) {
        //         swap(nums[k-1], nums[k]);
        //     }
        // }
        int not0count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) nums[not0count++] = nums[i];
        }
        for (int i = not0count; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};