#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, char>& lhs, pair<int, char>& rhs) {
    return lhs.first > rhs.first;
}

class Solution {
public:
    string ret = "";
    
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> chars{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        sort(chars.begin(), chars.end(), compare);
        while (chars[1].first > 0) {
            if (chars[0].first > chars[1].first) {
                pushBack(chars[0], 2);
            }
            else {
                pushBack(chars[0], 1);
            }
            pushBack(chars[1], 1);
            sort(chars.begin(), chars.end(), compare);
        }
        
        if (chars[0].first) 
            pushBack(chars[0], chars[0].first < 2 ? 1 : 2);
        
        return ret;
    }
    
private:
    inline void pushBack(pair<int, char>& p, int count) {
        p.first -= count;
        ret.push_back(p.second);
        if (count > 1) ret.push_back(p.second);
    }
};