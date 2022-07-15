#include "DataStructures.cpp"

using namespace std;

bool compare(vector<int>& lhs, vector<int>& rhs) {
    return lhs[0] < rhs[0];
}

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end(), compare);
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i+1][0]) return false;
        }

        return true;
    }
};