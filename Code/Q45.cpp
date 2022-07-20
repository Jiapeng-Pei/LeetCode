#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, steps = 0;
        while (end < nums.size() - 1) {
            int range = end;
            for (int i = start; i <= end; i++) {
                range = max(range, i + nums[i]);
                if (range >= nums.size() - 1) break;
            }

            steps++;
            start = end + 1;
            end = range;
        }

        return steps;
    }
};