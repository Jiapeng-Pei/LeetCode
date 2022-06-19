#include <stdio.h>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int ret = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] && i && j) {
                    int tmp = min(matrix[i][j-1], matrix[i-1][j-1]);
                    tmp = min(tmp, matrix[i-1][j]);
                    matrix[i][j] = tmp + 1;
                }
                ret += matrix[i][j];
            }
        }

        return ret;
    }
};

// state[i][j] = k : whether matrix[i][j] denotes the rightdown
// corner of a square with width = k.
// state[i][j] = state[i][j-1], state[i-1][j], state[i-1][j-1] + 1, if
// all this three location has the same value.
// state[i][j] = state[i][j], otherwise.
// use a while loop to iterate all possible size length.

// further improve: state[i][j] denotes the size of biggest square with matrix[i][j] as bottom-right squares.
// state[i][j] also denotes the number of square with [i][j] as bottom-right corner, which is easy to understand.
