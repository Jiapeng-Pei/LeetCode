#include "DataStructures.cpp"

using namespace std;

class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> chars(26, 0);
        for (char c : s) chars[c - 'a']++;
        sort(chars.rbegin(), chars.rend());
        int onePress = 9, twoPress = 9, ret = 0;
        for (int num : chars) {
            if (!num) break;
            if (onePress) 
                ret += num, onePress--;
            else if (twoPress) 
                ret += num * 2, twoPress--;
            else 
                ret += num * 3;
        }
        
        return ret;
    }
};