#include <vector>

using namespace std;

class NumArray {
public:
    int n = 0;
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        n = nums.size();
        
        // preSum[i] denotes the sum of numbers whose indexes are in range[0, i);
        preSum = vector<int>(n+1, 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = nums[i-1] + preSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */