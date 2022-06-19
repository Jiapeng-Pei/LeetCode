#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> strs(numRows);
        int index = 0;
        int direction = 1;
        for (char c : s) {
            strs[index].push_back(c);
            if (index == numRows - 1 && direction == 1) direction = -1;
            if (index == 0 && direction == -1) direction = 1;
            index += direction;
        }
        string ret = "";
        for (string s : strs) ret.append(s);
        return ret; 
    }
};