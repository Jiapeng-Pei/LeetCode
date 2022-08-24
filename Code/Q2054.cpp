#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<vector<int>> mem(n, vector<int>(2, 0));
        sort(events.begin(), events.end());
        return dfs(events, mem, 0, 2);
    }
    
private:
    int dfs(vector<vector<int>>& events, vector<vector<int>>& mem, int index, int k) {
        if (index >= events.size() || k == 0) return 0;
        if (mem[index][k-1]) return mem[index][k-1];
        mem[index][k-1] = max(dfs(events, mem, index + 1, k),
                         events[index][2] + dfs(events, mem, binarySearch(events, events[index][1]), k - 1));
        
        return mem[index][k-1];
    }
                         
    int binarySearch(vector<vector<int>>& events, int endTime) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] <= endTime) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left;
    }
};