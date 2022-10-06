#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> frequencyMap;
    
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) 
            frequencyMap[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        vector<int>& array = frequencyMap[target];
        return array[rand() % array.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */