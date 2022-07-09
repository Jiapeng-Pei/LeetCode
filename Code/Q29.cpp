#include <climits>

using namespace::std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int HALF_INT_MIN = INT_MIN >> 1;

        int negatives = 2;
        if (dividend > 0) {
            dividend = -dividend;
            negatives--;
        }        

        if (divisor > 0) {
            divisor = -divisor;
            negatives--;
        }

        int maxPower = -1;
        int maxDivisor = divisor;
        while (maxDivisor >= HALF_INT_MIN && dividend <= maxDivisor + maxDivisor) {
            maxPower += maxPower;
            maxDivisor += maxDivisor;
        }

        int ret = 0;
        while (dividend <= divisor) {
            if (dividend <= maxDivisor) {
                dividend -= maxDivisor;
                ret += maxPower;
            }
            maxDivisor >>= 1;
            maxPower >>= 1;
        }   

        return negatives == 1 ? ret : -ret;
    }
};
