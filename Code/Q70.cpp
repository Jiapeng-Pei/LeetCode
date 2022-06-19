#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> state(n+1, 1);
        for (int i = 2; i <= n; i++) {
            state[i] = state[i-2] + state[i-1];
        }

        return state[n];
    }
};