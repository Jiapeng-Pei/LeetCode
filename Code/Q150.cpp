#include <list>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        list<int> numStack;
        for (int i = 0; i < tokens.size(); ++i) {
            string cur = tokens[i];
            if (!checkOperator(tokens[i])) {
                numStack.push_back(stoi(cur));
            }
            else {
                int rhs = numStack.back();
                numStack.pop_back();
                int lhs = numStack.back();
                numStack.pop_back();
                switch (cur[0])
                {
                case '+':
                    numStack.push_back(lhs + rhs);
                    break;
                case '-':
                    numStack.push_back(lhs - rhs);
                    break;
                case '*':
                    numStack.push_back(lhs * rhs);
                    break;
                case '/':
                    numStack.push_back(lhs / rhs);
                    break;
                default:
                    break;
                }
            }
        }

        return numStack.back();
    }

    int checkOperator(string s) {
        if (s.size() != 1) return 0;
        return s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/';
    }
};