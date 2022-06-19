#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int i = nums.size() - 2;
        for (; i > -1 && nums[i] >= nums[i+1]; i--);
        if (i > -1) {
            int j = nums.size() - 1;
            for (; nums[j] <= nums[i]; j--);
            swap(nums[i], nums[j]);
        }

        auto it = nums.begin();
        for (int k = 0; k < i + 1; k++) it++;
        reverse(it, nums.end());
    }
};