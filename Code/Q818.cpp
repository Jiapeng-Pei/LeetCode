#include <vector>
#include <climits>
#include <math.h>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        vector<int> state(target + 1, INT_MAX);
        state[0] = 0;
        int r = 1;
        for (int i = 1; i <= target; i++) {
            if (i == pow(2, r) - 1) {
                state[i] = r;
                r++;
            }
            else {
                int lower = pow(2, r - 1) -1;
                int upper = pow(2, r) - 1;
                // reverse, go another j steps and reverse again.
                // In this case, the remaining distance is i - (2^(r-1)-1-2^j+1) = i-2^(r-1)+2^j
                for (int j = 0; j < r-1; j++) {
                    state[i] = min(state[i], r+1+j+state[i-pow(2, r-1)+pow(2, j)]);
                }
                state[i] = min(state[i], r+1+state[upper-i]);
            }
        }

        return state[target];
    }
};