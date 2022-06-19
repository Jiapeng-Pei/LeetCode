#include <vector>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if the number in nums is start of a potential streak
        // like, set[number - 1] doesn't exist, then we calculate the length of streak.
        // else we just skip it. because it has be calculated in its streak!
        unordered_set<int> set(nums.begin(), nums.end());
        int ret = 0;
        for (int n : nums) {
            if (set.count(n - 1)) continue;
            int end = n + 1;
            while (set.count(end)) end++; 
            ret = max(ret, end - n);
        }

        return ret;
    }
};