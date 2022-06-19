#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        list<int> monoStack;
        monoStack.push_back(-1);
        int ret = -1, n = heights.size();
        for (int i = 0; i < n; i++) {
            while (monoStack.back() != -1 && heights[i] <= heights[monoStack.back()]) {
                int curHeight = heights[monoStack.back()];
                monoStack.pop_back();
                ret = max(ret, (i - monoStack.back() - 1) * curHeight);
            }
            monoStack.push_back(i);
        }

        while (monoStack.back() != -1) {
            int curHeight = heights[monoStack.back()];
            monoStack.pop_back();
            ret = max(ret, (n - 1 - monoStack.back()) * curHeight);
        }

        return ret;
    }
};