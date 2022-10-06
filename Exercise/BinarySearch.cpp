#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

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
    list<int> nums{1, 2, 3, 4, 6, 6, 7, 8};

    set<int> numsSet{nums.begin(), nums.end()};
    auto it1 = lower_bound(numsSet.begin(), numsSet.end(), 2);
    auto it2 = upper_bound(numsSet.begin(), numsSet.end(), 2);
    cout << *it1 << endl;
    cout << *it2 << endl;
    map<int, int> numsMap;
    for (int n : nums) numsMap[n] = 1;
    auto it3 = lower_bound(numsMap.begin(), numsMap.end(), 2);
    auto it4 = upper_bound(numsMap.begin(), numsMap.end(), 2);
    cout << it3->first << endl;
    cout << it4->first << endl;


    // auto it1 = lower_bound(nums.begin(), nums.end(), 6);
    // nums.insert(it1, 5);
    // for (int n : nums) cout << n << " ";
    // cout << endl;
    // auto it3 = lower_bound(nums.begin(), nums.end(), 2);
    // auto it4 = upper_bound(nums.begin(), nums.end(), 6);
    // cout << *it4 << endl;
    // it3 = nums.erase(it3);
    // for (int n : nums) cout << n << " ";
    // cout << endl;
    // it4 = nums.end();
    // it4--;
    // nums.erase(it3, it4);
    // for (int n : nums) cout << n << " ";
}
