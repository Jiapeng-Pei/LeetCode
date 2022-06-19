#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        list<char> stack;
        unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
            }
            else {
                if (stack.back() != map[c]) return false;
                else stack.pop_back();
            }
        }
        return !stack.size();
    }
};