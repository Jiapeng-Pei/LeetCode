#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            nums[slow++] = nums[fast++];
            while (fast < nums.size() && nums[fast] == nums[fast-1]) fast++;
        }

        return slow;
    }
};

