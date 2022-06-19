#include <vector>
#include <iostream>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
	int left = 0, right = nums.size(), mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    
    // 这里返回的是第一个大于等于target的元素下标。
    return left;
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    cout << binarySearch(nums, 9) << " ";
    cout << binarySearch(nums, 8) << " ";
    cout << binarySearch(nums, 7) << " ";
    cout << binarySearch(nums, 0) << " ";
}
