#include <string>
#include <stdio.h>

using namespace::std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int m = haystack.size(), n = needle.size(), p = 0;
        for (; p < m - n + 1; p++) {
            if (haystack[p] != needle[0]) continue;
            if (haystack.substr(p, n) == needle) return p;
        }

        return -1;
    }
};