#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int imax = ret, imin = ret;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(imin, imax);
            
            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);

            ret = max(ret, imax);
        }

        return ret;
    }
};