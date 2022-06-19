#include <stdio.h>
#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            ret ^= nums[i];
            ret ^= i; 
        }

        return ret;
    }
};