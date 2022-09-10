#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        list<int> monoStack;
        int n = nums.size(), ret = 0;
        // To find the next/prev max element, I need to keep a decreasing stack.
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            while (monoStack.size() && cur >= nums[monoStack.back()]) {
                int j = monoStack.back();
                monoStack.pop_back();
                int k = monoStack.size() ? monoStack.back() : -1;
                if (nums[j] >= left && nums[j] <= right) ret += (i - j) * (j - k);
            }
            monoStack.push_back(i);
        }
        
        while (monoStack.size()) {
            int j = monoStack.back();
            monoStack.pop_back();
            int k = monoStack.size() ? monoStack.back() : -1;
            if (nums[j] >= left && nums[j] <= right) ret += (n - j) * (j - k);
        }
        
        return ret;
    }
};