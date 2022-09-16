#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ret = (long long)(k + 1) * k / 2;
        for (int n : set<int>{nums.begin(), nums.end()}) {
            if (n <= k) 
                ret += (++k) - n;
        }
        return ret;
    }
};