#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cur = INT_MIN;
        sort(intervals.begin(), intervals.end());
        int ret = 0;
        for (auto& it : intervals) {
            // there is no overlapping.
            if (it[0] >= cur) {
                cur = it[1];
            }
            else {
                ret++;
                cur = min(cur, it[1]);
            }
        }
        
        return ret;
    }
};