// 1. at every position of the generated string, there're two choices. '(' or ')'
// it's possible to put ( if current number of ( is smaller than the limit.
//  
#include <vector>
#include <stdio.h>
#include <string>

using namespace::std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string temp = "";
        recursive(temp, 0, 0, n, ret);
        return ret;
    }

    void recursive(string& temp, int numLeft, int numRight, int n, vector<string>& ret) {
        if (temp.size() == n * 2) {
            ret.push_back(temp);
            return;
        }   
        if (numLeft < n) {
            temp.push_back('(');
            recursive(temp, numLeft + 1, numRight, n ,ret);
            temp.pop_back();
        }
        if (numRight < numLeft) {
            temp.push_back(')');
            recursive(temp, numLeft, numRight + 1, n ,ret);
            temp.pop_back();
        }
    }
};