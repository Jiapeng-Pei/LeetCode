#include <string>
#include <stdio.h>
#include <list>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        list<int> stack;
        int result = 0;
        int sign = 1;
        int number = 0;
        for (int i = 0; i < s.length(); i++) {
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
                stack.push_back(result);
                stack.push_back(sign);
                sign = 1;
                result = 0;
            }
            else if (c == ')') {
                result += sign * number;
                number = 0;
                int topSign = stack.back();
                stack.pop_back();
                int topNum = stack.back();
                stack.pop_back();
                result *= topSign;
                result += topNum;
            }
        }
        
        result += sign * number;
        return result;
    }
};