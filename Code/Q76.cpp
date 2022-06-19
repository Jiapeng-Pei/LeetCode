// while right < size() && current window isn't qualified, expand right.
// while (current window is valid)
//    update result
//    shrink left side of the window.
// 这个问题的难点在于如何高效判断当前window是不是一个有效的window。把这个方法背下来吧，没什么办法。

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <climits>

using namespace::std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetMap;
        int minLength = INT_MAX;
        string ret = "";
        for (char c : t) targetMap[c]++;
        // [left, right)

        int left = 0, right = 0, count = targetMap.size();
        while (right < s.size()) {
            char add = s[right++];
            if (--targetMap[add] == 0) count--;

            while (left < right && count == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    ret = s.substr(left, right - left);
                }

                char remove = s[left++];
                if (++targetMap[remove] == 1) count++;
            } 
        }
        return ret;
    }
};

int main() {
    unordered_map<char, int> test;
    test['a'] = 1;
    cout << test.size();
    test['c']; 
    cout << test.size();
}