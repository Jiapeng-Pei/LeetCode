#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> state(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                state[i][j] = state[i-1][j] + state[i][j-1];
            }
        }
        return state[m-1][n-1];
    }
};

// state[0][0] = 1; state[0][i] = 1, 0 < i < n; state[i][0] = 1;
// state[i][j] = state[i-1][j] + state[i][j-1] 