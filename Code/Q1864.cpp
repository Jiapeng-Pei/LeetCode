#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int count0 = 0, count1 = 0;
        for (char c : s) count1 += c == '1' ? 1 : 0;
        count0 = n - count1;
        if (count1 - count0 > 1 || count1 - count0 < -1) return -1;
        if (n % 2) {
            char leadChar = count1 > count0 ? '1' : '0';
            int right = 0;
            for (int i = 0; i < n; i += 2) right += s[i] == leadChar ? 1 : 0;
            return n/2+1 - right;
        }
        else {
            int right = 0;
            for (int i = 0; i < n; i += 2) right += s[i] == '1' ? 1 : 0;
            right = max(right, n/2 - right);
            return n/2 - right;
        }
    }
};