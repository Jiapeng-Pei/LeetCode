#include <string>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ret = "";
        while (i > -1 || j > -1) {
            int sum = carry;
            sum += i > -1 ? a[i--] - '0' : 0;
            sum += j > -1 ? b[j--] - '0' : 0;
            ret.push_back('0' + sum % 2);
            carry = sum / 2;
        }
        if (carry) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }

    // string addBinary(string a, string b) {
    //     string ret;
    //     int ptrA = a.size() - 1, ptrB = b.size() - 1;
    //     bool carry = false;
    //     while (ptrA > -1 && ptrB > -1) {
    //         if (a[ptrA] == '1' && b[ptrB] == '1') {
    //             ret.push_back(carry ? '1' : '0');
    //             carry = true;
    //         }
    //         else if (a[ptrA] == '0' && b[ptrB] == '0') {
    //             ret.push_back(carry ? '1' : '0');
    //             carry = false;
    //         }
    //         else {
    //             ret.push_back(carry ? '0' : '1');
    //         }
    //         ptrA--;
    //         ptrB--;
    //     }

    //     while (ptrA > -1) {
    //         if (carry) {
    //             ret.push_back(a[ptrA] == '1' ? '0' : '1');
    //             carry = a[ptrA--] == '1';
    //         } else {
    //             ret.push_back(a[ptrA--]);
    //         }
    //     }

    //     while (ptrB > -1) {
    //         if (carry) {
    //             ret.push_back(b[ptrB] == '1' ? '0' : '1');
    //             carry = b[ptrB--] == '1';
    //         } else {
    //             ret.push_back(b[ptrB--]);
    //         }
    //     }

    //     if (carry) ret.push_back('1');
    //     reverse(ret.begin(), ret.end());

    //     return ret;
    // }
};