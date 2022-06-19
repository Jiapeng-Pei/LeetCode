#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int n : nums) ret ^= n;
        return ret;
    }
};