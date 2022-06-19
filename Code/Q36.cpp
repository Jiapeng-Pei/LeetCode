#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;

        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> boxes(9, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') continue;

                int val = board[i][j] - '0';
                int pos = 1 << val - 1;
                
                if (rows[i] & pos) return false;
                rows[i] |= pos;

                if (cols[j] & pos) return false;
                cols[j] |= pos;
                
                int index = 3 * (i / 3) + j / 3;
                if (boxes[index] & pos) return false;
                boxes[index] |= pos;
            }
        }

        return true;
    }
};