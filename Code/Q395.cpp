#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int left = 0, right = 0, todo = 0;
        unordered_map<char, int> frequencyMap;
        while (right < s.size()) {
            char c = s[right++];
            if (++frequencyMap[c] < k) todo++;
            
        }
    }
};