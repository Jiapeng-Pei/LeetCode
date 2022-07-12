#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        int ptr1 = 0, ptr2 = lower;
        while (ptr1 < nums.size()) {
            if (nums[ptr1] == ptr2) {
                ptr1++;
                ptr2++;
            }
            else if (nums[ptr1] > ptr2) {
                appendRange(ret, ptr2, nums[ptr1] - 1);
                ptr2 = nums[ptr1] + 1;
                ptr1++;
            }
        }

        appendRange(ret, ptr2, upper);
        return ret;
    }

    void appendRange(vector<string>& ret, int from, int to) {
        if (from > to) return;
        if (to == from) {
            ret.push_back(to_string(from));
        }
        else {
            string s = to_string(from);
            s.append("->");
            s.append(to_string(to));
            ret.push_back(s);
        }
    }  
};