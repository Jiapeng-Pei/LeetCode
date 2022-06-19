#include <string>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        sort(strs.begin(), strs.end());
        string front = strs.front();
        string back = strs.back();
        string ret = "";
        for (int i = 0; i < min(front.size(), back.size()); i++) {
            if (front[i] == back[i]) ret.push_back(front[i]);
            else break;
        } 

        return ret;
    }
};