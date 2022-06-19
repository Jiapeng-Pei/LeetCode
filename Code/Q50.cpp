#include <stdio.h>
#include <iostream>

using namespace::std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        
        double res = 1;
        long absN = n;
        if (n < 0) {
            absN = abs((long)n);
            x = 1 / x;
        }

        while (absN > 0) {
            if ((absN & 1) == 1) res *= x;
            x *= x;
            absN >>= 1;
        }

        return res;
    }
};