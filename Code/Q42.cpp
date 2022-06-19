#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int ret = 0, left = 0, right = height.size() - 1;
        int leftMax = height[0], rightMax = height[right];
        while (left <= right) {
            if (leftMax <= rightMax) {
                leftMax = max(leftMax, height[left]);
                ret += leftMax - height[left++];
            }
            else {
                rightMax = max(rightMax, height[right]);
                ret += rightMax - height[right--];
            }
        }

        return ret;
    }
};