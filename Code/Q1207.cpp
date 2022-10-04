#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequencyMap;
        for (int i : arr) frequencyMap[i]++;
        set<int> uniqueSet;
        for (auto pair : frequencyMap) {
            if (uniqueSet.count(pair.second)) 
                return false;
            else 
                uniqueSet.insert(pair.second);
        }
        
        return true;
    }
};