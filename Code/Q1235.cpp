#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> mem(n, 0);
        // sort jobs according to start time. I need all attributes of the job, startTime, endTime and profit.
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        
        return dfs(jobs, mem, 0, n);
    }
    
    
    
private: 
    // 如果只不选相同开始时间job中的某一个，怎么能确保我能选中相同开始时间的其他job呢？Use an index.
    int dfs(vector<vector<int>>& jobs, vector<int>& mem, int index, int n) {
        if (index >= n) return 0;
        if (mem[index]) return mem[index];
        
        vector<int>& curJob = jobs[index];
        int nxtIndex = findNextJob(jobs, curJob[1]);
        mem[index] = max(dfs(jobs, mem, index + 1, n),
                        curJob[2] + dfs(jobs, mem, nxtIndex, n));
        
        return mem[index];
    }
    
    int findNextJob(vector<vector<int>>& jobs, int endTime) {
        int left = 0, right = jobs.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid][0] < endTime) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left;
    }
};