#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        for (int i = 0; i < sz; i++) dp[i][i] = true;
        

        for (int i = sz - 1; i >= 0; i--) {
            for (int j = i + 1; j < sz; j++) {
                if (j - i == 1) 
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
            }
        }

        int ret = 0;
        for (vector<bool> vect : dp) {
            for (bool b : vect) if (b) ret++;
        }

        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.countSubstrings("aaa") << endl;
    return 0;
}