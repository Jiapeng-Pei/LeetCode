#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        unordered_map<char, int> letterMap;
        int maxLength = INT_MIN;
        int right = 0, left = 0, duplicate = 0;
        while (right < s.size()) {
            char addChr = s[right++];
            if (++letterMap[addChr] == 2) duplicate++;

            while (left < right && duplicate) {
                char delChr = s[left++];
                if (--letterMap[delChr] == 1) duplicate--;
            }

            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};