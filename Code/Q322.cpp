#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) return 0;
        vector<int> state(amount + 1, INT_MAX);
        state[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
             for (int c : coins) {
                 if (c > i) break;
                 if (state[i - c] != INT_MAX) state[i] = min(state[i], 1 + state[i - c]);
             }
        }

        return state[amount] == INT_MAX ? -1 : state[amount];
    }
};