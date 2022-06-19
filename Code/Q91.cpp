#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (!s.size() || s[0] == '0') return 0;
        int n = s.size();
        // state[i] represents the decode options of string[0, i). There's no leading 0s.
        vector<int> state(n + 1, 0);
        state[0] = 1;
        state[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i-1] != '0') state[i] += state[i-1];
            int twodigits = stoi(s.substr(i-2, 2));
            if (twodigits >= 10 && twodigits <= 26) state[i] += state[i-2];
            if (!state[i]) break;
        }
        return state[n];
    }
};