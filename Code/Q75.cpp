#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0;
        for (int n : nums) {
            if (!n) count0++;
            else if (n == 1) count1++;
        }
        int i = 0;
        while (i < count0) nums[i++] = 0;
        while (i < count0 + count1) nums[i++] = 1;
        while (i < nums.size()) nums[i++] = 2;
    }
};