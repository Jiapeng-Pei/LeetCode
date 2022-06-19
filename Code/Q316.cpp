#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dupTimes(26, 0);
        vector<bool> exist(26, false);
        string ret = "";
        
        for (char c : s) {
            dupTimes[c - 'a']++;
        }
        
        for (char c : s) {
            int index = c - 'a';
            dupTimes[index]--;
            if (exist[index]) continue;
            while (ret.size() && dupTimes[ret.back() - 'a'] && c < ret.back()) {
                exist[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            ret.push_back(c);
            exist[index] = true;
        }

        return ret;
    }
};
