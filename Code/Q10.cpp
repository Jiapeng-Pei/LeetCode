#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) return s.size() == 0;

        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= p.size(); j++) {
            dp[0][j] = p[j-1] == '*' && dp[0][j-2];
        }

        for (int j = 1; j <= p.size(); j++) {
            for (int i = 1; i <= s.size(); i++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};