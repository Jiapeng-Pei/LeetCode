#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}};
        int ret = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            char c = s[i];
            if (map[c] >= map[s[i+1]]) ret += map[c];
            else ret -= map[c];
        }
        ret += map[s[s.size()-1]];
        return ret;
    }
};