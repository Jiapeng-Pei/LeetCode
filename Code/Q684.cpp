#include <vector>

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
        if (u == root[u]) return u;
        root[u] = find(root[u]);
        return root[u];
    }

    bool Union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;

        if (rank[rootU] < rank[rootV]) {
            root[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV]) {
            root[rootV] = rootU;
        }
        else {
            root[rootU] = rootV;
            rank[rootV] += 1;
        }
        count--;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (vector<int> e : edges) {
            int from = e[0] - 1, to = e[1] - 1;
            if (!uf.Union(from, to)) return e;
        }

        return { };
    }
};

int main() {
    vector<vector<int>> edges{{1,2}, {1, 3}, {2, 3}};
    Solution s;
    s.findRedundantConnection(edges);
}