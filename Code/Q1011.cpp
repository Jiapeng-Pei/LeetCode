#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN, right = 0, mid;
        for (int i = 0; i < weights.size(); i++) {
            left = max(left, weights[i]);
            right += weights[i];
        }
        
        while (left < right) {
            mid = left + (right - left) / 2;
            bool flag = isWithinTimeLimit(weights, days, mid);
            if (!flag) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left;
    }
    
    bool isWithinTimeLimit(vector<int>& weights, int days, int capcity) {
        int D = 0, cur = 0;
        for (int i = 0; i < weights.size() && D < days; i++) {
            cur += weights[i];
            if (cur > capcity) {
                D++;
                cur = weights[i];
            }
        }
        
        return D < days;
    }
};