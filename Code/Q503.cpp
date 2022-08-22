#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        if (n == 1) return ret;
        list<int> stack;
        for (int i = 0; i < nums.size() * 2; i++) {
            int index = i % nums.size();
            while (stack.size() && nums[stack.back()] < nums[index]) {
                ret[stack.back()] = nums[index];
                stack.pop_back();
            }
            stack.push_back(index);
        }

        return ret;
    }
};