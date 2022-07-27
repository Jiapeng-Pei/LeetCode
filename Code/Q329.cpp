#include <vector>

using namespace std;

class Solution {
public:
    int m = 0, n = 0;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // 0 represents this node hasn't been visited before in dfs.
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ret = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, dfs(matrix, dp, i, j, -1));
            }
        }

        return ret;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y, int lastVal) {
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= lastVal) return 0;
        if (dp[x][y]) return dp[x][y];
        int cur = matrix[x][y];
        dp[x][y] += 1;
        int m1 = max(dfs(matrix, dp, x - 1, y, cur), dfs(matrix, dp, x + 1, y, cur));
        int m2 = max(dfs(matrix, dp, x, y - 1, cur), dfs(matrix, dp, x, y + 1, cur));
        dp[x][y] += max(m1, m2);

        return dp[x][y];
    }
};