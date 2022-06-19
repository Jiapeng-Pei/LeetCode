#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        // check whether the numbers of X & O are correct.
        int xStep = 0, oStep = 0;
        int xWinCount = 0;
        int oWinCount = 0;
        for (string row : board) {
            for (char c : row) {
                if (c == 'X') {
                    xStep++;
                } 
                else if (c == 'O') {
                    oStep++;
                }
            }
        }
        if (xStep - oStep != 0 && xStep - oStep != 1) return false;

        for (int i = 0; i < 3; i++) {
            if (board[i] == "XXX") {
                xWinCount++;
            }
            else if (board[i] == "OOO") {
                oWinCount++;
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == 'X') xWinCount++;
                else oWinCount++;
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') xWinCount++;
            else oWinCount++;;
        }

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X') xWinCount++;
            else oWinCount++;
        }

        if (xWinCount && oWinCount) {
            return false;
        }
        int winCount = xWinCount ? xWinCount : oWinCount;
        bool xWin = xWinCount != 0;

        if (!winCount) return true;
        else {
            if (xWin && xStep - oStep == 1) return true;
            if (!xWin && xStep - oStep == 0) return true;
            return false;
        }
    }
};