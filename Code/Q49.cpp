#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if (!strs.size()) return ret;
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (map.count(s)) {
                map[s].push_back(strs[i]);
            }
            else {
                map[s] = vector<string>{strs[i]};
            }
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            ret.push_back(it->second);
        }

        return ret;
    }
};