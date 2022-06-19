#include <stdio.h>
#include <vector>
#include <list>

using namespace::std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> maxStack;
        vector<int> ret;

        for (int i = 0; i < k; i++) {
            while (maxStack.size() && nums[i] > nums[maxStack.back()]) {
                maxStack.pop_back();
            }
            maxStack.push_back(i);
        }
        ret.push_back(nums[maxStack.front()]);

        for (int rightIndex = k; rightIndex < nums.size(); rightIndex++) {
            // remove the leftmax element
            int leftIndex = rightIndex - k;
            if (maxStack.front() == leftIndex) {
                maxStack.pop_front();
            }

            // add the new element
            while (maxStack.size() && nums[rightIndex] > nums[maxStack.back()]) {
                maxStack.pop_back();
            }
            maxStack.push_back(rightIndex);

            // calculate the max Integer in current window
            ret.push_back(nums[maxStack.front()]);
        }

        return ret;
    }
};
