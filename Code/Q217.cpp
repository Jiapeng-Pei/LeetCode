#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        return set.size() < nums.size();
    }
};