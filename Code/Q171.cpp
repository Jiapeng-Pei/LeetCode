#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0;
        long base = 1;
        for (int i = columnTitle.size() - 1;i >= 0; i--) {
            char c = columnTitle[i];
            ret += int(c - 'A' + 1) * base;
            base *= 26;
        }

        return ret;
    }
};