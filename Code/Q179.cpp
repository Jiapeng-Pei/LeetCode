#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int& lhs, int& rhs) {
    string str1 = to_string(lhs), str2 = to_string(rhs);
    return stol(str1 + str2) > stol(str2 + str1);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (!nums[0]) return "0";

        string ret = "";
        for (int i : nums) ret.append(to_string(i));
        return ret;
    }
};