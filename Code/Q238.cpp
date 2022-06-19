#include <vector>

using namespace std;

class Solution {
public:
    // vector<int> productExceptSelf_1(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> preProduct(n), postProduct(n), ret(n);
    //     preProduct[0] = nums[0], postProduct[n - 1] = nums[n - 1];
    //     for (int i = 1; i < n; i++) {
    //         preProduct[i] = preProduct[i-1] * nums[i];
    //         postProduct[n-1-i] = postProduct[n-i] * nums[n-1-i];
    //     }
        
    //     ret[0] = postProduct[1], ret[n-1] = preProduct[n-2];
    //     for (int i = 1; i < n - 1; i++) {
    //         ret[i] = preProduct[i-1] * postProduct[i+1];
    //     }
    //     return ret;
    // }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            ret[i] = ret[i-1] * nums[i-1];
        }

        int postPro = 1;
        for (int i = n - 1; i > -1; i--) {
            ret[i] *= postPro;
            postPro *= nums[i];
        }

        return ret;
    }
};