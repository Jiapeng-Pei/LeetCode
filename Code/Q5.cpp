#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        string ret = "";
        ret.push_back(s.back());
        for (int i = 0; i < sz; i++) dp[i][i] = true;
        for (int i = sz - 1; i >= 0; i--) {
            for (int j = i + 1; j < sz; j++) {
                if (j - i > 1) dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                else dp[i][j] = s[i] == s[j];

                if (dp[i][j] && (j - i + 1 > ret.size())) ret = s.substr(i, j - i + 1);  
            }
        }

        return ret;
    }
};