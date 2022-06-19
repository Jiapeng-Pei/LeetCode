#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    int count;
    vector<int> root;
    vector<int> size;
    UnionFind(int n) {
        count = n;
        for (int i = 0; i < n; i++) {
            root.push_back(i);
            size.push_back(1);
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

        if (size[rootU] < size[rootV]) {
            root[rootU] = rootV;
            size[rootV] += size[rootU];
        }
        else {
            root[rootV] = rootU;
            size[rootU] += size[rootV];
        }

        count--;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }

    int setSize(int u) {
        return size[u];
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        sort(initial.begin(), initial.end());
        int n = graph.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j]) uf.Union(i, j);
            }
        }
        vector<int> removeSize(initial.size());
        unordered_map<int, int> map;
        // for each infected node, calculate its removal. and store it
        for (int i : initial) {
            map[uf.find(i)]++;
        }

        for (int i = 0; i < initial.size(); i++) {
            int root = uf.find(initial[i]);
            if (map[root] > 1) removeSize[i] = 0;
            else removeSize[i] = uf.setSize(root);
        }

        int maxSize = 0;
        int ret = initial[0];
        for (int i = 0; i < initial.size(); i++) {
            if (maxSize < removeSize[i]) {
                maxSize = removeSize[i];
                ret = initial[i];
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix{{1, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 1, 1, 1}, {0, 0, 0, 1, 1, 1}};
    vector<int> initial{2, 3};
    s.minMalwareSpread(matrix, initial);
}