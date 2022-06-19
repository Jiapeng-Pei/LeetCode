#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace::std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) 
            return false;
        vector<int> require(26, 0);
        vector<int> current(26, 0);
        for (int i = 0; i < s1.size(); i++) require[s1[i] - 'a']++;
        for (int i = 0; i < s2.size(); i++) {
            current[s2[i] - 'a']++;
            if (i >= s1.size()) current[s2[i - s1.size()] - 'a']--;
            if (require == current) return true;
        }

        return false;
    }
};