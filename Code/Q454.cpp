#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> firstHalf;
        unordered_map<int, int> secondHalf;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                firstHalf[n1 + n2]++;
            }
        }
        for (int n3 : nums3) {
            for (int n4 : nums4) {
                secondHalf[n3 + n4]++;
            }
        }

        int ret = 0;
        for (auto it : firstHalf) {
            ret += it.second * secondHalf[-it.first];
        }

        return ret;
    }  
};