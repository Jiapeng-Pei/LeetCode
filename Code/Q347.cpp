#include <vector>
#include <random>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int n : nums) map[n] += 1;
        vector<pair<int, int>> numFrequency(map.begin(), map.end());
        quickSort(numFrequency, 0, numFrequency.size() - 1, numFrequency.size() - k);
        vector<int> ret;
        // for (int i = 0; i < k; i++) {
        //     ret.push_back(numFrequency[i].first);
        // }
        for (int i = numFrequency.size() - 1; i >= numFrequency.size() - k; i--) {
            ret.push_back(numFrequency[i].first);
        }
        return ret;
    }

    void quickSort(vector<pair<int, int>>& nums, int left, int right, int target) {
        if (left >= right) return;
        int pivotIndex = rand() % (right - left + 1) + left;
        pivotIndex = partition(nums, left, right, pivotIndex);
        if (pivotIndex == target) {
            return;
        }
        else if (pivotIndex > target) {
            quickSort(nums, left, pivotIndex - 1, target);
        }
        else {
            quickSort(nums, pivotIndex + 1, right, target);
        }
    }

    int partition(vector<pair<int, int>>& nums, int left, int right, int k) {
        int endingIndex = left;
        int pivot = nums[k].second;
        swap(nums[k], nums[right]);
        for (int i = left; i < right; i++) {
            if (nums[i].second <= pivot) swap(nums[endingIndex++], nums[i]);
        }

        swap(nums[endingIndex], nums[right]);

        return endingIndex;
    }
};

int main() {
    vector<int> nums1 = {1};
    vector<int> nums2;
    int k = 1;
    for (int i = nums1.size() - 1; i >= nums1.size() - k; i--) {
        nums2.push_back(nums1[i]);
    }
}