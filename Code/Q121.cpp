#include <stdio.h>
#include <vector>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = prices[0];
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            max_profit = max_profit > prices[i] - cur_min ? max_profit : prices[i] - cur_min;
            cur_min = cur_min < prices[i] ? cur_min : prices[i];
        }
        return max_profit;
    }
};