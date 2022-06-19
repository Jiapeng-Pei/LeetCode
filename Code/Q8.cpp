#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        vector<vector<int>> stateChange{{1, 2, 3}, {3, 2, 3}, {3, 2, 3}};
        int state = 0, sign = 1;
        long value = 0;
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;
        for (; i < s.size() && state != 3; i++) {
            char c = s[i];
            int type = getImpactType(c);
            if (type == 1) {
                value = value * 10 + c - '0';
                if (sign == 1 && value > INT_MAX) return INT_MAX;
                else if (-1 * value < INT_MIN) return INT_MIN;
            }
            if (state == 0 && type == 0) {
                 sign = c == '+' ? 1 : -1;
            }

            state = stateChange[state][type];
        }

        return value * sign;
    }

    int getImpactType(char c) {
        if (c == '+' || c == '-') return 0;
        if (c >= '0' && c <= '9') return 1;
        return 2;
    }
};

