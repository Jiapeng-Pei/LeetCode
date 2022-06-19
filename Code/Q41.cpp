#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& i : nums) {
            if (i < 1 || i > n) i = 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % (n + 1)) {
                nums[nums[i]%(n+1) - 1] += n+1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < n + 1) return i + 1;
        }

        return n + 1;
    }
};