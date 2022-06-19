#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string count = countAndSay(n-1);
        string ret = "";
        // find all occurance of a char
        for (int i = 0; i < count.size();) {
            char cur = count[i];
            int next = i + 1;
            while (next < count.size() && count[next] == cur) next++;
            ret.push_back(char(next - i + '0'));
            ret.push_back(cur);
            i = next;
        }

        return ret;
    }
};