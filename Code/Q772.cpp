#include <string>
#include <list>

using namespace std;

class Solution {
public:
    int i = 0;
    
    int calculate(string s) {
        int lastNumber = 0, curNumber = 0, ret = 0;
        char opt = '+';

        for (; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') continue;

            if (c >= '0' && c <= '9') {
                curNumber = curNumber * 10 + int(c - '0');
            }
            else if (c == '(') {
                i++;
                // at here, index should be indexOf('(') + 1. Represents a new expression.
                curNumber = calculate(s);
                // at here, index should be the nearest indexOf(')').
            }
            else if (c == ')') {
                break;
            }
            else {
                calculate(ret, lastNumber, curNumber, opt);
                curNumber = 0;
                opt = c;
            }
        }
        calculate(ret, lastNumber, curNumber, opt);

        ret += lastNumber;
        return ret;
    }

    void calculate(int& ret, int& lastNumber, int curNumber, char opt) {
        if (opt == '+' || opt == '-') {
            ret += lastNumber;
            lastNumber = opt == '+' ? curNumber : -curNumber;
        }
        else if (opt == '*') {
            lastNumber *= curNumber;
        }
        else {
            lastNumber /= curNumber;
        }
    }
};

int main() {
    string str = "2*(5+5*2)/3+(6/2+8)";
    Solution s;
    printf("%d\n", s.calculate(str));
}