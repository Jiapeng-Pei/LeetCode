#include <vector>
#include <unordered_map>
#include <iostream>

using namespace::std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need;
        vector<int> ret;
        for (char c : p) need[c]++;
        int match = need.size();
        int right = 0;
        while (right < s.size()) {
            char c = s[right++];
            if (--need[c] == 0) match--;

            int left = right - p.size();
            if (left < 0) continue;
            if (match == 0) ret.push_back(left);
            char remove = s[left];
            if (++need[remove] == 1) match++;
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> ret = s.findAnagrams("aaabaaa", "aaa");
    for (int i : ret) cout << i << " ";
    cout << endl; 
}