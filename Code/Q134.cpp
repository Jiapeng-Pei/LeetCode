#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int minGas = INT_MAX;
        int minIndex = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if (minGas > total) {
                minGas = total;
                minIndex = i;
            }
        }

        if (total < 0) return -1;
        return (minIndex + 1) % n;
    }
};