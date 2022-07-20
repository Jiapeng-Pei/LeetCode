#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int cur : nums) {
            cur = cur % (n + 1);
            nums[cur-1] += n + 1;
        }

        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] / (n+1) == 2) {
                ret.push_back(i+1);
            }
        }

        return ret;
    }
};