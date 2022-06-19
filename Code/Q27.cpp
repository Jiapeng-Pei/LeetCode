#include <vector>
#include <stdio.h>

using namespace::std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (val > 50) return nums.size();
        if (nums.size() == 0) return 0;
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) nums[slow++] = nums[fast++];
            else fast++;
        }

        return slow;
    }
};