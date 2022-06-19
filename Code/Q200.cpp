#include <vector>

using namespace::std;

class UnionFind {
public:
    vector<int> root;
    vector<int> rank;
    int count;
    UnionFind(int n) {
        count = n;
        for (int i = 0; i < n; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int i) {
        if (root[i] == i) return i;
        root[i] = find(root[i]);
        return root[i];
    }

    bool Union(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return false;
        if (rank[rootI] < rank[rootJ]) {
            root[rootI] = rootJ;
        } 
        else if (rank[rootI] > rank[rootJ]) {
            root[rootJ] = rootI;
        }
        else {
            root[rootI] = rootJ;
            rank[rootJ]++;
        }
        count--;
        return true;
    }
};

class Solution {
public:

    // int numIslands(vector<vector<char>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int ret = 0;
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == '1' && !visited[i][j]) {
    //                 dfs(grid, visited, i, j);
    //                 ret++;
    //             }
    //         }
    //     }
    //     return ret;
    // }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> landIndex(m, vector<int>(n, -1));
        int index = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') landIndex[i][j] = index++;
            }
        }

        UnionFind uf(index);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (landIndex[i][j] > -1) {
                    if (i > 0 && landIndex[i-1][j] > -1) uf.Union(landIndex[i][j], landIndex[i-1][j]);
                    if (j > 0 && landIndex[i][j-1] > -1) uf.Union(landIndex[i][j], landIndex[i][j-1]);
                }
            }
        }

        return uf.count;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == '0')
            return;
        visited[i][j] = true;
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i, j-1);
        dfs(grid, visited, i, j+1);
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    s.numIslands(grid);
}