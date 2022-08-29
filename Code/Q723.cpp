#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> crushable;
        int count = detectCrushable(board, crushable);
        
        while (count) {
            dropCandies(board, crushable);
            count = detectCrushable(board, crushable);
        }
        
        return board;
    }
    
    int detectCrushable(vector<vector<int>>& board, vector<vector<bool>>& crushable) {
        int count = 0;
        crushable = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int j = 0;
            while (j < n) {
                int start = j++;
                while (j < n && board[i][j] == board[i][start]) j++;
                
                if (board[i][start] && j - start >= 3) {
                    while (start != j) {
                        if (!crushable[i][start]) count++;
                        crushable[i][start++] = true;
                    }
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            int i = 0;
            while (i < m) {
                int start = i++;
                while (i < m && board[i][j] == board[start][j]) i++;
                
                if (board[start][j] && i - start >= 3) {
                    while (start != i) {
                        if (!crushable[start][j]) count++;
                        crushable[start++][j] = true;
                    }
                }
            }
        }
        
        return count;
    }
    
    void dropCandies(vector<vector<int>>& board, vector<vector<bool>>& crushable) {
        for (int j = 0; j < n; j++) {
            signed slow = m - 1;
            for (signed fast = m - 1; fast >= 0; fast--) {
                if (crushable[fast][j]) continue; 
                board[slow--][j] = board[fast][j];
            }
            while (slow >= 0) board[slow--][j] = 0;
        }
    }
};