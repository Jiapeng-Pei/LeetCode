#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> visited(n, false);
        for (int p = 2; p * p <= n; p++) {
            if (visited[p]) continue;
            for (int j = p * p; j < n; j += p) visited[j] = true;
        }

        int ret = 0;
        for (int i = 2; i < n; i++) if (!visited[i]) ret += 1;
        return ret;
    }
};