// 1. I could calculate the sum of each set easily.
// 2. I could calculate the occurance of each number, by using a map.
// 3. use recursive to solve this problem.
// Outer recursion on k subsets:
// base case: k = 0
// Recursive case: k > 0
//        base case: curSubsetSum == targetSubsetSum
//        Recursive case: curSubsetSum < targetSubsetSum     

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace::std;

bool compare(int i, int j) {
    return i > j;
}

class Solution {
public:
    int subsetSum = 0;
    vector<bool> visited;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % k || nums.size() < k) return false;
        subsetSum = sum / k;
        for (int num : nums) if (num > subsetSum) return false;

        visited = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end(), compare);
        return canPartition(nums, k, 0, 0);
    }

    bool canPartition(vector<int>& nums, int restSet, int curSum, int nextIndex) {
        if (restSet == 1) return true;
        if (curSum == subsetSum) return canPartition(nums, restSet - 1, 0, 0);
        for (int i = nextIndex; i < nums.size(); i++) {
            if (visited[i] || nums[i] + curSum > subsetSum) continue;
            visited[i] = true;
            if (canPartition(nums, restSet, curSum + nums[i], i + 1)) return true;
            visited[i] = false;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{4,3,2,3,5,2,1};
    s.canPartitionKSubsets(nums, 4);
}