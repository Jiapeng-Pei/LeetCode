#include <string>

using namespace std;

class Solution {
public:
    string ret = "";
    
    string strWithout3a3b(int a, int b) {
        pair<int, char> bigger = {a, 'a'};
        pair<int, char> smaller = {b, 'b'};
        if (a < b) swap(bigger, smaller);
        while (smaller.first) {
            if (bigger.first > smaller.first) {
                addBack(bigger, 2);
                addBack(smaller, 1);
            }
            else {
                addBack(bigger, 1);
                addBack(smaller, 1);
            }
            if (bigger.first < smaller.first) swap(bigger, smaller);
        }
        
        if (bigger.first) addBack(bigger, bigger.first);
        
        return ret;
    }
    
private:
    inline void addBack(pair<int, char>& p, int count) {
        p.first -= count;
        ret.push_back(p.second);
        if (count > 1) ret.push_back(p.second);
    }
};