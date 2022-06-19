#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int ptr1 = 0, ptr2 = s.size() - 1;
        while (ptr1 < ptr2) swap(s[ptr1++], s[ptr2--]);
    }
};