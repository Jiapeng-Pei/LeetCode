#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> map{{1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'}};
        int base = 1000;
        string ret = "";
        while (base) {
            int cur = num / base;
            if (cur) {
                if (cur == 9) {
                    ret.push_back(map[base]);
                    ret.push_back(map[base * 10]);
                }
                else if (cur == 4) {
                    ret.push_back(map[base]);
                    ret.push_back(map[base * 5]);
                }
                else {
                    if (cur >= 5) {
                        ret.push_back(map[base * 5]);
                        cur -= 5;
                    } 
                    
                    for (int i = 0; i < cur; i++) ret.push_back(map[base]);
                }
            }
            
            num = num % base;
            base = base / 10;
        }
        
        return ret;
    }
};