#include "DataStructures.cpp"

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // construct a user map. The key is the username string, and value is a vector with visited websites.
        // then for every user, calculate every visit patterns and store the pattern as a special string.
        // then return the pattern with biggest score.
        int n = username.size();
        unordered_map<string, vector<pair<int, string>>> userVisitWebsites;
        for (int i = 0; i < n; i++) {
            userVisitWebsites[username[i]].push_back({timestamp[i], website[i]});
        }

        unordered_map<string, int> patterns;
        int maxScore = 0;
        // travere every user
        for (auto& p : userVisitWebsites) {
            vector<pair<int, string>>& visits = p.second;
            sort(visits.begin(), visits.end());
            set<string> distinctPatterns;
            int sz = visits.size();

            // traverse every pattern
            for (int i = 0; i < sz-2; i++) {
                for (int j = i+1; j < sz-1; j++) {
                    for (int k = j+1; k < sz; k++) {
                        string curPattern = visits[i].second + "#" + visits[j].second + "$" + visits[k].second;
                        distinctPatterns.insert(curPattern);
                    }
                }
            }
            
            for (string str : distinctPatterns) maxScore = max(maxScore, ++patterns[str]);
        }

        string str = "";
        for (auto& p : patterns) {
            if (p.second != maxScore) continue;
            if (str == "" || p.first < str) str = p.first;
        }
        
        int i1 = str.find_first_of('#');
        int i2 = str.find_first_of('$');
        return {str.substr(0, i1), str.substr(i1+1, i2-i1-1), str.substr(i2+1)};
    }
};