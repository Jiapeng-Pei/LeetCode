#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        if (n % 2) ret.push_back(0);
        for (int i = 1; i <= n / 2; i++) {
            ret.push_back(i);
            ret.push_back(-i);
        }
        
        return ret;
    }
};