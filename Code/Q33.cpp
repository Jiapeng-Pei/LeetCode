#include <stdio.h>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int num = 0;
            if ( (nums[mid] >= nums[0]) == (target >= nums[0]) )
            {
                // same side of nums[0]
                num = nums[mid];
            }
            else
            {
                num = (nums[mid] >= nums[0] ? 0x80000000 : 0x7FFFFFFF);
            }
            if (num < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left] == target ? 1 : 0;
    }
};