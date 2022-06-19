#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLength = 0;
        for (int i = 0; i < nums.size() && i <= maxLength; i++) {
            maxLength = max(maxLength, i + nums[i]);
            if (maxLength >= nums.size() - 1) return true;
        }        
        return false;
    }
};