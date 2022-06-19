#include <stdio.h>
#include <string>
#include <list>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ret;
        list<int> leftStack;
        for (int i = 0; i < s.size(); i++) {
            char cur = s[i];
            if (cur != '(' && cur != ')') continue;
            if (cur == '(') leftStack.push_back(i);
            else {
                if (leftStack.size()) 
                    leftStack.pop_back();
                else 
                    s[i] = '*';
                
            }
        }
        for (int index : leftStack) 
            s[index] = '*';

        for (int i = 0; i < s.size(); i++) 
            if (s[i] != '*') ret.push_back(s[i]);
        
        return ret;
    }
};

int main() {
    Solution s;
    s.minRemoveToMakeValid("lee(t(c)o)de)");
}

// Thoughts:
// 1. meet (, not sure whether to delete, add it to stack
// 2. meet ), if exist (, don't need to delete, else need to delete
// 3. the ( in the remaining stack need to be deleted.