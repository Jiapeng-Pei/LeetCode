#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        int n = columnNumber;
        while (n) {
            int cur = (n - 1) % 26;
            n = (n - 1) / 26;
            ret.push_back('A' + cur);
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// https://leetcode.com/problems/excel-sheet-column-title/discuss/441430/Detailed-Explanation-Here's-why-we-need-n-at-first-of-every-loop-(JavaPythonC++)
// This question is quite hard. Read the explaination when reviewing it.