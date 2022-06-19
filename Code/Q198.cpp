#include <stdio.h>
#include <vector>

using namespace::std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        if (!n) return ret;
        vector<int> state(n, 0);
        for (int i = 0; i < n; i++) {
            if (i <= 1) state[i] = nums[i];
            else if (i == 2) state[i] = nums[2] + state[0];
            else state[i] = nums[i] + max(state[i-2], state[i-3]);
            ret = max(state[i], ret);
        }

        return ret;
    }
};

// state[i] represents the max income of robbling all the vaild houses before index i;
// state[0] = nums[0], state[1] = num[1]
// state[2] = nums[2] + state[0], state[3] = nums[3] + state[0] || state[1]
// state[i] = nums[i] + max(state[i-2], state[i-3]);