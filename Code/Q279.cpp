#include <stdio.h>
#include <climits>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int bound = floor(sqrt(n));
        vector<int> squares(bound, 0);
        vector<int> state(n + 1, INT_MAX);
        state[0] = 0;
        for (int i = 0; i < bound; i++) squares[i] = (i + 1) * (i + 1);
        for (int i = 1; i <= n; i++) {
            for (int square : squares) {
                if (square > i) break;
                state[i] = min(state[i], state[i - square] + 1);
            }
        }

        return state[n];
    }
};