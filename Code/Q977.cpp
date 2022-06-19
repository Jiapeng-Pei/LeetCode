#include <vector>

using namespace std;

class Solution {
public:
    // With O(n) time complexity.
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        int i = 0;
        while (i < nums.size() && nums[i] < 0) i++;
        int j = i - 1;
        int count = 0;
        while (count < n) {
            int tmp = 0;
            if (j == -1) {
                tmp = nums[i++];
            }
            else if (i == n) {
                tmp = -nums[j--];
            }
            else if (nums[i] < -nums[j]) {
                tmp = nums[i++];
            }
            else {
                tmp = -nums[j--];
            }
            ret[count++] = tmp * tmp;
        }

        return ret;
    }
};