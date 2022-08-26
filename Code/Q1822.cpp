#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ret = 1;
        for (int n : nums) {
            if (!n) return 0;
            if (n < 0) ret *= -1; 
        }
        
        return ret;
    }
};