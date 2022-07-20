#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> map;
        for (int n : nums1) map[n]++;
        for (int n : nums2) {
            if (map[n]-- > 0) ret.push_back(n);
        }

        return ret;
    }
};