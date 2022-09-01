#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> plates;
        vector<int> ret;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '|') plates.push_back(i);
        }
        
        for (auto& query : queries) {
            int left = lower_bound(plates.begin(), plates.end(), query[0]) - plates.begin();
            int right = upper_bound(plates.begin(), plates.end(), query[1]) - plates.begin() - 1;
            
            ret.push_back(left < right ? plates[right] - plates[left] - right + left : 0);
        }
        
        return ret;
    }
};