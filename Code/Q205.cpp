#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_set<char> used;
        for (int i = 0; i < s.size(); i++) {
            if (!map.count(s[i])) {
                if (!used.count(t[i])) {
                    map[s[i]] = t[i];
                    used.insert(t[i]);
                }
                else {
                    return false;
                }
            }
            else if (map[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};