#include <vector>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int begin = 0, n = nums.size(), ret = 0;
        while (begin < n) {
            int end = begin;
            int negCount = 0, firstIndex = -1, lastIndex = -1;
            
            // Try to find an interval, [left, right)
            while (end < n && nums[end]) {
                if (nums[end] < 0) {
                    negCount++;
                    if (firstIndex == -1) firstIndex = end;
                    lastIndex = max(end, lastIndex);
                }
                end++;
            }
            
            // If the size of current interval is not 0 
            if (end - begin) {
                if (negCount % 2 == 0) {
                    ret = max(ret, end - begin);
                }
                else {
                    int curLength = max(lastIndex - begin, end - 1 - firstIndex);
                    ret = max(ret, curLength);
                }
            }
            
            begin = end + 1;
        }
        
        return ret;
    }
};