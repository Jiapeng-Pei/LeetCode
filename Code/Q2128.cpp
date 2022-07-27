#include <vector>

using namespace std;

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[0][i]) flipColumn(grid, i);
        }

        for (int i = 1; i < m; i++) {
            if (!checkRow(grid[i])) return false;
        }

        return true;
    }

    inline bool checkRow(vector<int>& row) {
        int start = row[0];
        for (int i : row) {
            if (i != start) return false;
        }

        return true;
    } 

    inline void flipColumn(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); i++) grid[i][col] = 1 - grid[i][col];
    }
};