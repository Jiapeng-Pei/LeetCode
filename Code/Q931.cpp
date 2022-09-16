#include <string>

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        long long zeroCount = 0, oneCount = 0;
        for (char c : s) {
            if (c == '0') zeroCount++;
            else oneCount++;
        }
        
        long long zeroBefore = 0, oneBefore = 0;
        long long ret = 0;
        for (char c : s) {
            if (c == '0') {
                ret += oneBefore * (oneCount - oneBefore);
                zeroBefore++;
            }
            else {
                ret += zeroBefore * (zeroCount - zeroBefore);
                oneBefore++;
            }
        }
        
        return ret;
    }
};