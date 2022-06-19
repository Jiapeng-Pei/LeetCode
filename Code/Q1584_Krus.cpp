#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace::std;

class UnionFind {
public:
    int count;
    vector<int> root;
    vector<int> rank;
    UnionFind(int n) {
        count = n;
        for (int i = 0; i < n; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int u) {
        while (root[u] != u) {
            root[u] = root[root[u]];
            u = root[u];
        }
        return u;
    }

    void Union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return;
        if (rank[rootU] < rank[rootV]) {
            root[rootU] = rootV;
            rank[rootV] += rank[rootU];
        }
        else {
            root[rootV] = rootU;
            rank[rootU] += rank[rootV];
        }
        count--;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Edge {
public:
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w): from(f), to(t), weight(w) {}
};

struct compare
{
    bool operator()(const Edge& lhs, const Edge& rhs) {
        return lhs.weight > rhs.weight;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return 0;

        // Initialize necessary data structure.
        int ret = 0;
        int edges = 0;
        int n = points.size();
        UnionFind uf(n);
        priority_queue<Edge, vector<Edge>, compare> pq;

        // Add all edges to pq
        for (int i = 0; i < n - 1; i++) {
            vector<int> from = points[i];
            for (int j = i + 1; j < n; j++) {
                vector<int> to = points[j];
                Edge e(i, j, abs(from[0] - to[0]) + abs(from[1] - to[1]));
                pq.push(e);
            }
        }

        // Add Edges to MST until n-1 edges
        while (pq.size() && edges < n - 1) {
            Edge curEdge = pq.top();
            pq.pop();
            if (uf.connected(curEdge.from, curEdge.to)) continue;

            // Add Edge.
            uf.Union(curEdge.from, curEdge.to);
            ret += curEdge.weight;
            edges++;
        }

        return ret;
    }
};

int main() {
    vector<vector<int>> points;
    points.push_back({0, 0}); 
    points.push_back({2, 2}); 
    points.push_back({3, 10}); 
    points.push_back({5, 2}); 
    points.push_back({7, 0}); 
    Solution s;
    s.minCostConnectPoints(points);
}