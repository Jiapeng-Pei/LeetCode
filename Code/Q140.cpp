#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace::std;

class Solution {
public:

    // dp solution
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_map<string, int> wordMap; 
        for (int i = 0; i < wordDict.size(); i++) {
            wordMap[wordDict[i]] = i;
        }
        unordered_map<int, vector<vector<int>> > sentenceMap;
        
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string newWord = s.substr(j, i - j);
                if (dp[j] && wordMap.count(newWord)) {
                    if (j == 0) {
                        vector<vector<int>> cur;
                        cur.push_back(vector<int>{wordMap[newWord]});
                        sentenceMap[i] = cur;
                    }
                    else {
                        if (!sentenceMap.count(i)) 
                            sentenceMap[i] = vector<vector<int>>{};

                        vector<vector<int>>& cur = sentenceMap[i];
                        for (vector<int>& vect : sentenceMap[j]) {
                            cur.push_back(vect);
                            cur.back().push_back(wordMap[newWord]);
                        }
                    }

                    dp[i] = true;
                }

            }
            // cout << "dp[" << i << "] = " << dp[i] << endl;
        }

        vector<string> ret;
        if (!dp[s.size()]) return ret;
        
        for (vector<int>& vect : sentenceMap[s.size()]) {
            string str;
            for (int& i : vect) {
                str.append(wordDict[i]);
                str.append(" ");
            }
            str.pop_back();
            ret.push_back(str);
        }

        return ret;
    }
};


int main() {
    Solution sol;
    vector<string> wordDict{"cat","cats","and","sand","dog"};
    vector<string> ret = sol.wordBreak("catsanddog", wordDict);
    for (string str : ret) 
        cout << str << endl;
}