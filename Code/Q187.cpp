#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.size() <= 10) return ret;
        unordered_map<int, int> sequenceMap;
        unordered_map<char, int> charToInt{{'A', 3}, {'C', 2}, {'G', 1}, {'T', 0}}; 
        int hash = 0;
        int base = 1;
        for (int i = 0; i < 10; i++) {
            hash = hash *        4 + charToInt[s[i]];
            base *= 4;
        }
        sequenceMap[hash]++;
        base /= 4;

        int left = 0, right = 10;
        while (right < s.size()) {
            hash = hash % base;
            hash = hash * 4 + charToInt[s[right++]];
            left++;

            if (sequenceMap[hash] == 1) 
                ret.push_back(s.substr(left, 10));
            
            sequenceMap[hash]++;
        }

        return ret;
    }
};