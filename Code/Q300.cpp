#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> array;
        for (int n : nums) {
            if (!array.size() || n > array.back()) {
                array.push_back(n);
            }
            else {
                array[binarySearch(array, n)] = n;
            }
        }

        return array.size();
    }

    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};