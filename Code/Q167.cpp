#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                ret.push_back(left + 1);
                ret.push_back(right + 1);
                return ret;
            }
        }

        // unreachable
        return ret;
    }
};