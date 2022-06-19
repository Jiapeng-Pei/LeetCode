#include <stdio.h>
#include <vector>

using namespace::std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = nums[0];

        for (int n : nums) {
            if (!count) candidate = n;
            count += n == candidate ? 1 : -1;
        }

        return candidate;
    }
};