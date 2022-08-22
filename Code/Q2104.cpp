#include <list>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        list<int> stack;
        int n = nums.size();
        int j, k;
        long long minSum = 0;
        for (int i = 0; i <= n; i++) {
            int cur = nums[i];
            while (stack.size() && nums[stack.back()] > (i == n ? INT_MIN : nums[i])) {
                int j = stack.back();
                stack.pop_back();
                int k = stack.size() ? stack.back() : -1;
                minSum += (long long)nums[j] * (i - j) * (j - k);
            }
            
            stack.push_back(i);
        }
        
        stack.erase(stack.begin(), stack.end());
        long long maxSum = 0;
        for (int i = 0; i <= n; i++) {
            int cur = nums[i];
            while (stack.size() && nums[stack.back()] < (i == n ? INT_MAX : nums[i])) {
                int j = stack.back();
                stack.pop_back();
                int k = stack.size() ? stack.back() : -1;
                maxSum += (long long)nums[j] * (i - j) * (j - k);
            }
            
            stack.push_back(i);
        }
        
        return maxSum - minSum;
    }
};