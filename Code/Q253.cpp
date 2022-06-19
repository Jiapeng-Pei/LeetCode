#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& lhs, vector<int>& rhs) {
    return lhs[0] < rhs[0];
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (vector<int>& meet : intervals) {
            if (!pq.size()) {
                pq.push(meet[1]);
                continue;
            }
            if (pq.top() <= meet[0]) {
                pq.pop();
            }
            pq.push(meet[1]);
        }

        return pq.size();
    }
};