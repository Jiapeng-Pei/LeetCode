#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace::std;

class Solution {
public:
    string reverseWords(string s) {
        if (!s.size()) return s;
        int sz = s.size(), slow = 0, fast = 0;
        while (fast < sz) {
            while (fast < sz && s[fast] == ' ') fast++;
            if (fast == sz) break;
            if (slow) s[slow++] = ' ';

            int wordStart = slow;
            while (fast < sz && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
            
            reverse(s.begin() + wordStart, s.begin() + slow);
        }

        s.resize(slow);
        reverse(s.begin(), s.end());

        return s;
    }
};

int main() {
    
}