#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) 
            return "1";
        vector<int> numArray;
        string ret = "";
        int divide = 1;
        for (int i = 1; i < n; i++) {
            divide *= i;
            numArray.push_back(i);
        }
        numArray.push_back(n);
        k--;
        for (int i = n - 1; i >= 1; i--) {
            int cur = k / divide;
            ret += to_string(numArray[cur]);
            numArray.erase(numArray.begin() + cur);
            k = k % divide;
            divide /= i;     
        }
        ret += to_string(numArray[0]);
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 3) << " " << s.getPermutation(4, 9) << " " << s.getPermutation(3, 1) << endl;
}