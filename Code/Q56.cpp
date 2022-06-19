#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace::std;

bool compare(vector<int> lhs, vector<int> rhs) {
    return lhs[0] < rhs[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) 
            return intervals;

        vector<vector<int>> ret;

        // sort intervals     
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> current = intervals[0];

        // add new interval to return or merge intervals.
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > current[1]) {
                ret.push_back(current);
                current = intervals[i];
            }
            else {
                current[1] = max(current[1], intervals[i][1]);
            }
        }
        ret.push_back(current);

        return ret;
    }
};