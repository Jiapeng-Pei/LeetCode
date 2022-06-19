#include <vector>
#include <stdio.h>

using namespace::std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) return bfs(grid, visited, i, j);
            }
        }

        return 0;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        // Encounter border, add Perimeter by 1.
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return 1;
        // Encounter water, add Perimeter by 1.
        if (grid[x][y] == 0) return 1;
        // We donnot add duplicate cases.
        if (visited[x][y]) return 0;
        
        int ret = 0;
        visited[x][y] = true;
        ret +=  bfs(grid, visited, x - 1, y);
        ret +=  bfs(grid, visited, x + 1, y);
        ret +=  bfs(grid, visited, x, y - 1);
        ret +=  bfs(grid, visited, x, y + 1);

        return ret;
    }
};

