#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (!k) return 0;
        unordered_map<char, int> map;
        int ret = 0, left = 0, right = 0, duplicates = 0;
        // the window is [left, right)
        while (right < s.size()) {
            char addChar = s[right++];
            if (++map[addChar] == 1) duplicates++;
            while (duplicates > k) {
                char delChar = s[left++];
                if (--map[delChar] == 0) duplicates--;
            }
            
            ret = max(ret, right - left);
        }

        return ret;
    }
};