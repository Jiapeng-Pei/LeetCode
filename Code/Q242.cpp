#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> letters;
        for (char c : s) letters[c]++;
        for (char c : t) {
            if (letters[c]-- == 0) return false;
        }

        return true;
    }
};