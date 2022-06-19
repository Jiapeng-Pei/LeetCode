#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int right = 0, left = 0;
        // Window size = k + 1;
        while (right < nums.size()) {
            int toAdd = nums[right++];

            if (right - left > k + 1) {
                int toDel = nums[left++];
                --map[toDel];
            } 
            if (++map[toAdd] == 2) return true;
        }

        return false;
    }
};