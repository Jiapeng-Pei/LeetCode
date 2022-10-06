#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {        
        int n = nums.size();
        int ret = 0, preSum = 0;
        
        unordered_map<int, int> reminderTimes{{0, 1}};
        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            int remainder = preSum % k;
            remainder += remainder < 0 ? k : 0;
            ret += reminderTimes[remainder];
            reminderTimes[remainder]++;
        }
        
        return ret;
    }
};