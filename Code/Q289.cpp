#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] <= 0) continue;
                if (i && j) board[i-1][j-1] += board[i-1][j-1] > 0 ? 1 : -1;
                if (i) board[i-1][j] += board[i-1][j] > 0 ? 1 : -1;
                if (i && j+1 < n) board[i-1][j+1] += board[i-1][j+1] > 0 ? 1 : -1;
                if (i+1 < m && j) board[i+1][j-1] += board[i+1][j-1] > 0 ? 1 : -1;
                if (i+1 < m) board[i+1][j] += board[i+1][j] > 0 ? 1 : -1;
                if (i+1 < m && j+1 < n) board[i+1][j+1] += board[i+1][j+1] > 0 ? 1 : -1;
                if (j) board[i][j-1] += board[i][j-1] > 0 ? 1 : -1;
                if (j+1 < n) board[i][j+1] += board[i][j+1] > 0 ? 1 : -1;
            }
        }

        for (vector<int>& rows : board) {
            for (int& n : rows) {
                if (n <= 0) {
                    n = n == -3 ? 1 : 0;
                }
                else {
                    n = n == 3 || n == 4 ? 1 : 0;
                }
            }
        }
    }
};