#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <queue>    
#include <iostream>    

using namespace::std;

struct compare {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first > rhs.first;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ret = 0;
        if (!points.size()) return 0;
        // Initialize data structures.
        int edges = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        vector<bool> visited(points.size(), false); 

        // Add the first node as the initial node.       
        visited[0] = true;
        vector<int> point0 = points[0];
        for (int i = 1; i < points.size(); i++) {
            vector<int> cur = points[i];
            pq.push(make_pair(abs(point0[0] - cur[0]) + abs(point0[1] - cur[1]), i));
        }

        while (edges < points.size() - 1) {
            // Find the valid edge in pq.
            pair<int, int> cur = pq.top();
            pq.pop();
            if (visited[cur.second]) continue;

            // Add all the possible edges starting from the added point.
            ret += cur.first;
            edges++;
            int index = cur.second;
            visited[index] = true;
            for (int i = 1; i < points.size(); i++) {
                if (visited[i]) continue;
                vector<int> to = points[i];
                pq.push(make_pair(abs(points[index][0] - to[0]) + abs(points[index][1] - to[1]), i));
            }
        }

        return ret;
    }
};

int main() {
    priority_queue<pair<int, int>> pq;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push(make_pair(1, 1));
    pq.push(make_pair(2, 1));
    pq.push(make_pair(3, 1));
    while (pq.size()) {
        pair<int, int> p = pq.top();
        pq.pop();
        cout << p.first << endl;
    }
}