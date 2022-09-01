#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int fresh = 0;
        list<pair<int, int>> bfs;
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    bfs.push_back({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (!fresh) return 0;
        
        int mins = -1;
        // all the oranges in the gird is rotten, add a minute to result at the beginning.
        // Try to add new oranges into the queue.
        while (bfs.size()) {
            mins++;
            int size = bfs.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> cur = bfs.front();
                bfs.pop_front();
                int nextX, nextY;    
                for (auto& drt : directions) {
                    nextX = cur.first + drt[0];
                    nextY = cur.second + drt[1];
                    if (inGrid(nextX, nextY) && grid[nextX][nextY] == 1) {
                        fresh--;
                        grid[nextX][nextY] = 2;
                        bfs.push_back({nextX, nextY});
                    }
                }
                
                int z = 0;
            }
        } 
        
        return fresh ? -1 : mins;
    }
    
private: 
    inline bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};