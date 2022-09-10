#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n < 3) return n;
        unordered_map<int, int> numOfFruits;
        // [left, right) denotes the current substring.
        int left = 0, right = 0, types = 0, ret = 0;
        while (right < n) {
            int cur = fruits[right++];
            if (++numOfFruits[cur] == 1) types++;
            
            while (types > 2) {
                int remove = fruits[left++];
                if (--numOfFruits[remove] == 0) types--;
            }
            
            ret = max(ret, right - left);
        }
        
        return ret;
    }
};