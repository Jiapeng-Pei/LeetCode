#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSums{{0, 1}};
        int n = nums.size();
        int sum = 0, ret = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (preSums.count(sum - k)) ret += preSums[sum - k];
            preSums[sum]++;
        }        
        
        return ret;
    }
};