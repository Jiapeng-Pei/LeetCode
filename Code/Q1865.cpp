#include <vector>
#include <map>
#include <unordered_map>
#include <map>

using namespace std;

class FindSumPairs {
public:
    map<int, int> array1;
    unordered_map<int, int> array2;
    vector<int> nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int n : nums1) array1[n]++;
        for (int n : nums2) array2[n]++;
        this->nums2 = nums2;        
    }
    
    void add(int index, int val) {
        array2[nums2[index]]--;
        nums2[index] += val;
        array2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ret = 0;
        for (auto it = array1.begin(); it != array1.end() && it->first < tot; it++) {
            int num = it->first, frequency = it->second;
            ret += frequency * array2[tot - num];
        }

        return ret;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */