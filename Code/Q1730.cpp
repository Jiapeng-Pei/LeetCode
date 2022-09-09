#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        auto p = findStart(grid);
        int x = p.first, y = p.second;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        list<pair<int, int>> queue;
        dist[x][y] = 0;
        queue.push_back({x, y});
        int nxtX, nxtY;
        while (queue.size()) {
            x = queue.front().first, y = queue.front().second;
            queue.pop_front();
            for (vector<int>& drt : directions) {
                nxtX = x + drt[0];
                nxtY = y + drt[1];
                // To move to next grid, the space must be unvisited and not an abstacle.
                if (inGrid(nxtX, nxtY) && dist[nxtX][nxtY] == -1 && grid[nxtX][nxtY] != 'X') {
                    if (grid[nxtX][nxtY] == '#') return dist[x][y] + 1;
                    dist[nxtX][nxtY] = dist[x][y] + 1;
                    queue.push_back({nxtX, nxtY});
                }
            }
        }
        
        return -1;        
    }

private:
    int m;
    int n;
    pair<int, int> findStart(vector<vector<char>>& grid) {
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == '*') return {i, j};
        
        return {0, 0};
    }
    
    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};