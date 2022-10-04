#include <stdio.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    set<int> bigMonth{1, 3, 5, 7, 8, 10, 12};
    int dayOfYear(string date) {
        vector<int> _date = {stoi(date.substr(0, 4)), stoi(date.substr(5, 2)), stoi(date.substr(8))};
        int ret = _date[2];
        for (int i = 1; i < _date[1]; i++) {
            if (bigMonth.count(i)) 
                ret += 31;
            else
                ret += i != 2 ? 30 : isLeap(_date[0]) ? 29 : 28;
        }
        
        return ret;
    }
    
    inline bool isLeap(int i) {
        return i % 4 == 0 && (i % 100 || i % 400 == 0);
    }
};