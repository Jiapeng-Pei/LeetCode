#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Trie {
public:
    bool isEnd;
    string* str;
    unordered_map<char, Trie*> children;
    
    Trie() {
        isEnd = false;
        str = nullptr;
    }
    
    void addChildren(string& s) {
        Trie* cur = this;
        for (char c : s) {
            if (!cur->children.count(c)) {
                cur->children[c] = new Trie();
            }
            cur = cur->children[c];
        }
        cur->str = &s;
        cur->isEnd = true;
    }
};

void findMiniStrings(vector<string>& vec, int& count, Trie* cur) {
    if (!cur || !count) return;
    if (cur->isEnd) {
        vec.push_back(*cur->str);
        count--;
    }
    if (!count) return;
    for (int i = 0; i < 26; i++) {
        findMiniStrings(vec, count, cur->children[char('a' + i)]);
    }
}

void dfs(Trie* cur) {
    if (!cur) return;
    if (cur->isEnd) cout << cur->str << endl;
    
    for (auto it : cur->children) dfs(it.second);
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        for (string& s : products) {
            root->addChildren(s);
            // dfs(root);
        }   
        
        vector<vector<string>> ret;
        for (char c : searchWord) {
            vector<string> suggestion;
            if (!root) {
                ret.push_back(suggestion);
                continue;
            }
            root = root->children[c];
            int num = 3;
            findMiniStrings(suggestion, num, root);
            ret.push_back(suggestion);
        } 
        
        return ret;
    }
};

// int main() {
//     Solution s;
//     vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
//     s.suggestedProducts(products, "mouse");
// }