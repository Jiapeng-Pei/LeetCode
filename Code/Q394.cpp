class Solution {
#include <string>

using namespace std;

public:    
    int i = 0;
    string decodeString(string s) {
        string ret = "";
        for (; i < s.size() && s[i] != ']'; i++) {
            if (s[i] <= '0' || s[i] >= '9') {
                ret.push_back(s[i]);
                continue;
            }  

            int next = i + 1;
            while (next < s.size() && s[next] != '[') next++;
            int n = stoi(s.substr(i, next - i));
            i = next + 1;
            string innerStr = decodeString(s);
            for (int j = 0; j < n; j++) ret.append(innerStr);
        }
        
        return ret;
    }
};