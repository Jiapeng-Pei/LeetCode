#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int>& lhs, vector<int>& rhs) {return lhs[0] < rhs[0]; } 

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end(), compare);
        int curTime = events[0][0], endTime = 100000;
        int index = 0, ret = 0;
        while (curTime <= endTime) {
            // remove unattendable events
            while (pq.size() && pq.top() < curTime) pq.pop();
             
            // add attendable events to pq
            while (index < events.size() && events[index][0] == curTime) {
                pq.push(events[index++][1]);
            }
            if (pq.size()) {
                pq.pop();
                ret++;
            }
            curTime++;
        }
        
        return ret;
    }
};