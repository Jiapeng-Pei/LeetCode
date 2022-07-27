#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int i = 0;

    int calculate(string s) {
        int result = 0;
        int sign = 1;
        int number = 0;
        for (; i < s.size(); i++) {
            char c = s[i];
            
            if (c >= '0' && c <= '9') {
                number = number * 10 + (int)(c - '0');
            }
            else if (c == '+') {
                result += number * sign;
                sign = 1;
                number = 0;
            }
            else if (c == '-') {
                result += number * sign;
                sign = -1;
                number = 0;
            }
            else if (c == '(') {
                // treat the whole () as a number. 
                i++;
                number = calculate(s);
                // when arrive here, i = index(')'), so it is right.
            }
            else if (c == ')') {
                break;
            }
        }

        result += sign * number;
        return result;
    }
};