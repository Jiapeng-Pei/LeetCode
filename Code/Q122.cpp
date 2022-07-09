#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int cur = prices[i];
            profit += cur > holdPrice ? cur - holdPrice : 0;
            holdPrice = cur;
        }

        return profit;
    }
};