#include <vector>

using namespace::std;

// rank denotes the upper bound for a tree's height.
// the rank may be useful, but it may be not useful as well. 
// If every node in the tree is accessed, then the height of 
// the tree will always be 2. So rank is not needed. 
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
