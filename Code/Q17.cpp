#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, string> map{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ret;
    string tmp = "";

    vector<string> letterCombinations(string digits) {
        if (digits == "") return ret;
        recursive(digits, 0);
        return ret;
    }

    void recursive(string& digits, int index) {
        if (index == digits.size()) {
            ret.push_back(tmp);
            return;
        }

        char cur = digits[index];
        string charArray = map[cur];
        for (char c : charArray) {
            tmp.push_back(c);
            recursive(digits, index + 1);
            tmp.pop_back();
        }
    }
};