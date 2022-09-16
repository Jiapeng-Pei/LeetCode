#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> preSum;
    int m = 0, n = 0;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        preSum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + matrix[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // row1 and col1 represent the upper left point. 
        // The two points represents the inside corner of the rectangle.
        // add No.1: row2+1, col2+1; add No.2: row1, col1;
        // sub No.1: row2+1, col1; sub No.2: row1, col2+1 
        return preSum[row2+1][col2+1] + preSum[row1][col1] - preSum[row2+1][col1] - preSum[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */