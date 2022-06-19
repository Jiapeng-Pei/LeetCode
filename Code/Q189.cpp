#include <stdio.h>
#include <vector>
#include <algorithm>  
#include <iostream>

using namespace::std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k <= 0)
            return;
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> example(7);
    for (int i = 0; i < 7; ++i) {
        example[i] = i;
    }
    Solution s;
    s.rotate(example, 3);
    for (int i = 0; i < 7; i++) {
        cout << example[i] << " "; 
    }
    cout << endl;
}