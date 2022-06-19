#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ptr1 = s.size() - 1;
        while (s[ptr1] == ' ') ptr1--;
        int ptr2 = ptr1;
        while (ptr2 >= 0 && s[ptr2] != ' ') ptr2--;

        return ptr1 - ptr2;
    }
};