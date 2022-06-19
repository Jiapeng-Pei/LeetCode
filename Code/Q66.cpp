#include <vector>
#include <stdio.h>

using namespace::std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i > -1 && carry; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
        }

        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};