#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flights(n + 1, 0);
        for (vector<int>& booking : bookings) {
            flights[booking[0]] += booking[2];
            if (booking[1] < n) flights[booking[1] + 1] -= booking[2];
        }
        
        vector<int> ret;
        for (int i = 1; i <= n; i++) {
            flights[i] += flights[i-1];
            ret.push_back(flights[i]);
        }
        
        return ret;
    }
};