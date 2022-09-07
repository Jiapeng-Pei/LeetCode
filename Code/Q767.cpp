#include "DataStructures.cpp"

bool compare(pair<char, int>& lhs, pair<char, int>& rhs) {
    return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second > rhs.second;
}

class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<char, int>> chars;
        for (int i = 0; i < 26; i++) chars.push_back({char('a' + i), 0});
        for (char c : s) chars[c - 'a'].second++;
        sort(chars.begin(), chars.end(), compare);
        
        string ret = "";
        while (true) {
            if (chars[1].second < 1) {
                if (chars[0].second > 1) return "";
                if (chars[0].second) ret.push_back(chars[0].first);
                return ret;
            }
            
            ret.push_back(chars[0].first);
            chars[0].second--;
            ret.push_back(chars[1].first);
            chars[1].second--;
            sort(chars.begin(), chars.end(), compare);
        }
        
        return ret;
    }
};