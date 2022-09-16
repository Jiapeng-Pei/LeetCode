#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    // partition函数的input是一个目标index，一段数组。
    // 将该段数组中所有小于nums[index]的值移到index左边，将该数组所有大于nums[index]的值移到index右边。
    // 最后返回input index中的元素经过上述操作后所在的index。

    int partition(vector<int>& nums, int left, int right, int index) {
        int pivotVal = nums[index];
        swap(nums[index], nums[right]);
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivotVal) swap(nums[storeIndex++], nums[i]);
        }
        swap(nums[storeIndex], nums[right]);
        
        return storeIndex;
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left <= right) return nums[left];
        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);

        if (pivotIndex == k) return nums[pivotIndex];
        else if (pivotIndex < k) return quickSelect(nums, pivotIndex + 1, right, k);
        else return quickSelect(nums, left, pivotIndex - 1, k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left >= right) return nums[left];
        
        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);
        
        if (pivotIndex == k) {
            return nums[k];
        } 
        else if (pivotIndex < k) {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
        else {
            return quickSelect(nums, left, pivotIndex - 1, k);
        }
    }
};