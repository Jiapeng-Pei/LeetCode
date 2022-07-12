#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<string>> ret;
    vector<string> cur;
    vector<vector<string>> partition(string s) {
        int length = s.size();
        vector<vector<bool>> state(length, vector<bool>(length, false));
        for (int i = 0; i < length; i++) state[i][i] = true;
        for (signed int i = length - 2; i >= 0; i--) {
            state[i][i+1] = s[i] == s[i+1];
            for (int j = i + 2; j < length; j++) {
                state[i][j] = s[i] == s[j] && state[i+1][j-1];
            }
        }

        recursive(state, s, 0);
        return ret;
    }

    void recursive(vector<vector<bool>>& state, string& str, int begin) {
        if (begin == str.size()) {
            ret.push_back(cur);
            return;
        }
        for (int end = begin; end < str.size(); end++) {
            if (!state[begin][end]) continue;
            cur.push_back(str.substr(begin, end - begin + 1));
            recursive(state, str, end + 1);
            cur.pop_back();
        }
    }
};
