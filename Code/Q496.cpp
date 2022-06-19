#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        list<int> monoStack;
        unordered_map<int, int> map;
        for (int n : nums2) {
            while (monoStack.size() && n > monoStack.back()) {
                map[monoStack.back()] = n;
                monoStack.pop_back();
            }
            monoStack.push_back(n);
        }

        for (int n : nums1) {
            ret.push_back(map.count(n) ? map[n] : -1);
        }

        return ret;
    }
};