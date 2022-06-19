#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace::std;

class Solution {
public:

    // dp solution
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] represents whether substring [0, i) could be represented as a combination of 
        // words in dictionary. dp[0] is undefined and will be set as true.
        vector<bool> dp(s.size() + 1, false);
        set<string> wordSet; 
        for (string s : wordDict) {
            wordSet.insert(s);
        }

        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i && !dp[i]; j++) {
                dp[i] = dp[j] && wordSet.count(s.substr(j, i - j));
            }
            // cout << "dp[" << i << "] = " << dp[i] << endl;
        }

        return dp.back();
    }
};

int main() {
    string str = "catsandog";
    vector<string> wordDict{"cats","dog","sand","and","cat"};
    Solution solution;
    solution.wordBreak(str, wordDict);
}