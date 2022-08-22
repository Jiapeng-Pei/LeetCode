#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<string, int> websitesMap;
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        int websiteIndex = 1;
        unordered_map<string, vector<pair<int, int>>> userMap;
        unordered_map<int, int> patternMap;
        
        for (int i = 0; i < n; i++) {
            string& user = username[i];
            if (!userMap.count(user)) userMap[user] = vector<pair<int, int>>();
            string& site = website[i];
            if (!websitesMap.count(site)) websitesMap[site] = websiteIndex++;
            int j = websitesMap[site];
            int t = timestamp[i];
            userMap[user].push_back({t, j});
        }
        
        for (auto& it : userMap) {
            vector<pair<int, int>>& patterns = it.second;
            sort(patterns.begin(), patterns.end(), compare1);
            int l = patterns.size();
            for (int i = 0; i < l - 2; i++) {
                for (int j = i + 1; j < l - 1; j++) {
                    for (int k = j + 1; k < l; k++) {
                        vector<string>& p{patterns[i], patterns[j], patterns[k]};
                        int id = getPatternId(websitesMap, p);
                        patternMap[id]++;
                    }
                }
            }
        }
        
        int maxP = 0;
        for (auto& it : patternMap) {
            maxP = max(maxP, it.second);
        }
        vector<int> candidates;
        for (auto& it : patternMap) {
            if (it.second == maxP) candidates.push_back(it.first);
        }
        sort(candidates.begin(), candidates.end(), ) 
        
        return vector<string>();
    }
    
private:
    bool compare2(int lhs, int rhs) {
        for (int i = 0; i < 3; i++) {
            int l = lhs % 11, lhs /= 11;
            int r = rhs % 11, rhs /= 11;
        }
    }
    
    bool compare1(pair<int, int>& lhs, pair<int, int>& rhs) {
        return lhs.first < rhs.first;
    }
    
    int getPatternId(unordered_map<string, int>& websitesMap, vector<string>& pattern) {
        int id = 0;
        for (signed i = 2; i >= 0; i--) {
            id = id * 11 + websitesMap[pattern[i]];
        }
        
        return id;
    }
};