#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ret = 0, i = 0;
        for (; i < n || pq.size(); i++) {
            if (i < n && apples[i]) {
                pq.push({i + days[i], apples[i]});
            }
            
            // clear rotten apples.
            while (pq.size() && pq.top().first <= i) pq.pop();
            
            // throw away empty apple.
            if (pq.size()) {
                ret++;
                pair<int, int> p = pq.top();
                pq.pop();
                if (--p.second > 0) pq.push(p); 
            }
        }
        
        return ret;
    }
};