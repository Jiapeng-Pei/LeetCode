#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> array(26, 0);
        for (char c : s) array[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (array[s[i] - 'a'] == 1) return i;
        } 

        return -1;
    }
};