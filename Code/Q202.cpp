#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        int fast = nextNum(n), slow = n;
        while (fast != 1 && slow != fast) {
            fast = nextNum(nextNum(fast));
            slow = nextNum(slow);
        }

        return fast == 1;
    }

    int nextNum(int n) {
        int ret = 0;
        while (n) {
            int cur = n % 10;
            n = n / 10;
            ret += cur * cur;
        }
        return ret;
    }
};