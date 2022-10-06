#include <vector>
#include <string>

using namespace std;

#define ll long long int

class Solution {    
public:
    const ll mod = 1e9 + 7;

    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        
        // preSum[i][j] denotes the number of apples between [0][0] && [i][j]
        vector<vector<int>> preSum(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                preSum[i][j] = pizza[i-1][j-1] == 'A' ? 1 : 0;
                preSum[i][j] += preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];
            }
        }
        
        // the right bottom corner (n-1, m-1) and left upper corner together can represent a pizza.
        // dp[i][j][k] denotes the number of ways to cut pizza so the upper left corner is (i, j)
        // and we cut total k pizzas.
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(k+1, 0)));
        dp[0][0][1] = 1;
        
        for (int cut = 2; cut <= k; cut++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dp[i][j][cut-1] == 0) continue;
                    
                    // Traverse every horizontal cut
                    for (int x = i+1; x < n; x++) {
                        if (hasApple(preSum, i, j, x-1, m-1) && hasApple(preSum, x, j, n-1, m-1)) {
                            dp[x][j][cut] += dp[i][j][cut-1];
                            dp[x][j][cut] %= mod;
                        }
                    }
                    
                    for (int y = j+1; y < m; y++) {
                        if (hasApple(preSum, i, j, n-1, y-1) && hasApple(preSum, i, y, n-1, m-1)) {
                            dp[i][y][cut] += dp[i][j][cut-1];
                            dp[i][y][cut] %= mod;
                        }
                    }
                }
            }
        }
        
        ll ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret += dp[i][j][k];
                ret %= mod;
            }
        }
        
        return ret;
    }
    
private:
    bool hasApple(vector<vector<int>>& preSum, int lx, int ly, int rx, int ry) {
        int rec1 = preSum[lx][ly];
        int rec2 = preSum[lx][ry+1];
        int rec3 = preSum[rx+1][ly];
        int rec4 = preSum[rx+1][ry+1];
        
        return rec4 - rec3 - rec2 + rec1 > 0;
    }
};