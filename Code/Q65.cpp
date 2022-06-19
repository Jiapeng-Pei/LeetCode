#include <stdio.h>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0) return false;

        enum state{START, START_SIGN, DIGIT_1, DIGIT_SIGN, DIGIT_2, E_BEGIN, E_SIGN, E_AFTER, END};
        state curState(START);
        for (char c : s) {
            switch (curState)
            {
            case START:
                if (c == '+' || c == '-') 
                    curState = START_SIGN;
                else if (c >= '0' && c <= '9') 
                    curState = DIGIT_1;
                else if (c == '.') 
                    curState = DIGIT_SIGN;
                else 
                    curState = END;
                break;

            case START_SIGN:
                if (c >= '0' && c <= '9') 
                    curState = DIGIT_1;
                else if (c == '.') 
                    curState = DIGIT_SIGN;
                else 
                    curState = END;
                break;
                
            case DIGIT_1:
                if (c >= '0' && c <= '9') 
                    curState = DIGIT_1;
                else if (c == '.') 
                    curState = DIGIT_2;
                else if (c == 'e' || c == 'E')
                    curState = E_BEGIN;
                else 
                    curState = END;
                break;

            case DIGIT_SIGN:
                if (c >= '0' && c <= '9') 
                    curState = DIGIT_2;
                else 
                    curState = END;
                break;

            case DIGIT_2:
                if (c >= '0' && c <= '9')
                    curState = DIGIT_2;
                else if (c == 'e' || c == 'E')
                    curState = E_BEGIN;
                else 
                    curState = END;
                break;

            case E_BEGIN:
                if (c == '-' || c == '+')
                    curState = E_SIGN;
                else if (c >= '0' && c <= '9') 
                    curState = E_AFTER;
                else 
                    curState = END;
                break;

            case E_SIGN:
                if (c >= '0' && c <= '9')
                    curState = E_AFTER;
                else 
                    curState = END;
                break;

            case E_AFTER:
                if (c >= '0' && c <= '9') 
                    curState = E_AFTER;
                else 
                    curState = END;
                break;
        
            case END:
                return false;
                break;
            }
        }

        if (curState == DIGIT_1 || curState == DIGIT_2 || curState == E_AFTER)
            return true;
        else 
            return false;
    }
};

int main() {
    Solution solution;
    string correct[]{"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    string wrong[]{"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};
    for (string s : correct) {
        cout << solution.isNumber(s) << " ";
    }
    cout << endl;
    
    for (string s : wrong) {
        cout << solution.isNumber(s) << " ";
    }
    cout << endl;
}