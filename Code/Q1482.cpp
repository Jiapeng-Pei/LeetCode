#include <vector>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1, right = 1, n = bloomDay.size(), mid;
        if (n < m * k) return -1;
        for (int i : bloomDay) right = max(right, i);
        if (n == m * k) return right;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            bool flag = isValid(bloomDay, m, k, mid);
            if (!flag) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    
private:
    bool isValid(vector<int>& bloomDay, int m, int k, int day) {
        int i = 0, count = 0, flow = 0;
        for (int i = 0; i < bloomDay.size() && count < m; i++) {
            if (bloomDay[i] > day) {
                flow = 0;
            }
            else if (++flow >= k) {
                flow = 0;
                count++;
            }
        }      
        return count == m;
    }
};