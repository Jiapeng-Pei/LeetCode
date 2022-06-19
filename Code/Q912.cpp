#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    // [left, right)
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);

        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }

    int partition(vector<int>& nums, int left, int right, int k) {
        int pivotVal = nums[k];
        swap(nums[k], nums[right]);
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] <= pivotVal) swap(nums[storeIndex++], nums[i]);
        }
        swap(nums[storeIndex], nums[right]);

        return storeIndex;
    }
};