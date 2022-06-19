#include <climits>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        auto it1 = s.begin(), it2 = s.end();
        if (x < 0) it1++;
        std::reverse(it1, it2);
        int ret = 0;
        try {
            ret = stoi(s);
        }
        catch (exception e) {
            return 0;
        }
        return ret;
    }
};