#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int m = 0;
    int n = 0;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        if (!m || !n) return false; 
        if (word == "") return true;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, visited, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited, string& target, int index) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != target[index]) return false;
        if (++index == target.size()) return true;

        bool ret = false;
        visited[x][y] = true;
        ret = dfs(board, x-1, y, visited, target, index) || dfs(board, x+1, y, visited, target, index) || dfs(board, x, y-1, visited, target, index) || dfs(board, x, y+1, visited, target, index);
        visited[x][y] = false;

        return ret;
    }
};