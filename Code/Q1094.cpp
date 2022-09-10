#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diffs(1001, 0);
        for (auto& trip : trips) {
            int from = trip[1], to = trip[2], num = trip[0];
            diffs[from] += num;
            diffs[to] -= num;
        }
        
        if (diffs[0] > capacity) return false;
        for (int i = 1; i < diffs.size(); i++) {
            diffs[i] += diffs[i-1];
            if (diffs[i] > capacity) return false;
        }
        
        return true;
    }
};