/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

#include <vector>

using namespace std;

class TicTacToe {
public:
    int n;
    vector<int> rows;
    vector<int> cols;
    vector<int> diagnols{0, 0};
    TicTacToe(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) rows.push_back(0), cols.push_back(0);
    }
    
    int move(int row, int col, int player) {
        if (player == 1) {
            if (++rows[row] == n) return 1;
            if (++cols[col] == n) return 1;
            if (row == col && ++diagnols[0] == n) return 1;
            if (row + col == n - 1 && ++diagnols[1] == n) return 1; 
        }
        else {
            if (--rows[row] == -n) return 2;
            if (--cols[col] == -n) return 2;
            if (row == col && --diagnols[0] == -n) return 2;
            if (row + col == n - 1 && --diagnols[1] == -n) return 2;
        }

        return 0;
    }
};