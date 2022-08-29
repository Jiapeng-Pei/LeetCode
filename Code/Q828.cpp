#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> lastAppear(26, vector<int>(2, -1));
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            // 正常情况下是有三个数字代表occurance. 当读到第三个数字时，需要计算第二个数字的contribute。
            // 如果此时没有三个数字呢？如果没有数字，那就把当前数字加入第二个slot中，等下次计算；
            // 第一个slot是不需要使用的。因为
            if (lastAppear[c][1] == -1) {
                lastAppear[c][1] = i;
            }
            else {
                ret += (lastAppear[c][1] - lastAppear[c][0]) * (i - lastAppear[c][1]);
                lastAppear[c][0] = lastAppear[c][1];
                lastAppear[c][1] = i;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            ret += (lastAppear[i][1] - lastAppear[i][0]) * (n - lastAppear[i][1]);
        }
        
        return ret;
    }
};