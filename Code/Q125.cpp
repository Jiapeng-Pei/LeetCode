#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        int offset = 'A' - 'a';
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                str.push_back(c);
            }
            else if (c >= 'a' && c <= 'z') {
                str.push_back(c);
            }
            else if (c >= 'A' && c <= 'Z') {
                str.push_back(c - offset);
            }
        }

        int forward = 0, backward = str.size() - 1;
        while (forward < backward) {
            if (str[forward++] != str[backward--]) return false;
        }

        return true;
    }
};

// 0 1 2 3, get passby; 0 1 2, meet at 1