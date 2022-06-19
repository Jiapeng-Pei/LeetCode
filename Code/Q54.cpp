#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret(m * n, 0);
        int i = 0, face = 0;
        for (; i < ret.size(); i++) {
            ret[i] = matrix[x][y];
            matrix[x][y] = 999;
            int nextX = x + direction[face][0];
            int nextY = y + direction[face][1];
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || matrix[nextX][nextY] == 999) 
                face = (face + 1) % 4;
            x += direction[face][0];
            y += direction[face][1];
        }

        return ret;
    }
};