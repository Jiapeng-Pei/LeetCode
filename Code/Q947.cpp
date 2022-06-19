#include <vector>
#include <unordered_map>

using namespace std;

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
        if (u == v) return false;
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
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> rowMap;
        unordered_map<int, int> colMap;
        int n = stones.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            vector<int> stone = stones[i];
            if (!rowMap.count(stone[0])) rowMap[stone[0]] = i;
            if (!colMap.count(stone[1])) colMap[stone[1]] = i;
            uf.Union(rowMap[stone[0]], i);
            uf.Union(colMap[stone[1]], i);
        }

        return n - uf.count;
    }
};