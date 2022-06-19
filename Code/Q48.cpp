#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int squareSize = matrix.size();
        int row = 0, n = squareSize - 1;

        // from observation, suppose a point has index(i, j). after rotation:
        // new row index = j; new col index = n - i.
        while (squareSize > 1) {
            for (int col = row; col < row + squareSize - 1; col++) {
                // point 1: (i, j); point 2: (j, n - i); point3: (n - i, n - j); point 4: (n - j, i).
                int tmp = matrix[n - col][row];
                matrix[n - col][row] = matrix[n - row][n - col];
                matrix[n - row][n - col] = matrix[col][n - row];
                matrix[col][n - row] = matrix[row][col];
                matrix[row][col] = tmp;
            }
            squareSize -= 2;
            row++;
        }
    }
};