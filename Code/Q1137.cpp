#include <vector>

using namespace::std;

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) return n == 0 ? 0 : 1;
        vector<int> state(n+1, 0);
        state[1] = 1, state[2] = 1;
        for (int i = 3; i <= n; i++) {
            state[i] = state[i-3] + state[i-2] + state[i-1];
        }
        return state[n];
    }
};