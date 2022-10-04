#include <stdio.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    set<int> bigMonth{1, 3, 5, 7, 8, 10, 12};
    
    int daysBetweenDates(string date1, string date2) {
        int days1 = calculateDays(date1);
        int days2 = calculateDays(date2);
        
        return abs(days1 - days2);
    }
    
    bool isLeap(int year) {
        return year % 4 == 0 && (year % 100 || year % 400 == 0);
    }
    
    int calculateDays(string& dateStr) {
        vector<int> date = {stoi(dateStr.substr(0, 4)), stoi(dateStr.substr(5, 2)), stoi(dateStr.substr(8))};
        int ret = date[2];
        for (int i = 1970; i < date[0]; i++) 
            ret += isLeap(i) ? 366 : 365;
        
        for (int i = 1; i < date[1]; i++) {
            if (bigMonth.count(i)) 
                ret += 31;
            else 
                ret += i != 2 ? 30 : isLeap(date[0]) ? 29 : 28;
        }
        
        return ret;
    }
};