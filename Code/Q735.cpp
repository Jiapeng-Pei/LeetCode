#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        for (int n : asteroids) {
            if (n > 0 || !ret.size() || ret.back() < 0) {
                ret.push_back(n);
                continue;
            }
            
            // stack top > 0, and n < 0.
            while (ret.size() && ret.back() > 0 && n) {
                // The size if the same.
                if (ret.back() + n == 0) {
                    ret.pop_back();
                    n = 0;
                }
                // the negative one is bigger
                else if (ret.back() + n < 0) {
                    ret.pop_back();
                }
                // the positive one is bigger
                else {
                    n = 0;
                }
            }
            
            if (n) ret.push_back(n);
        }
        
        return ret;
    }
};