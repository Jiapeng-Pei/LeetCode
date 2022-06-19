#include <stdio.h>
#include <string>
#include <unordered_map> 

using namespace std;

class Trie {
public:
    Trie() {
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            if (!cur->children[c]) 
                cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (char c : word) {
            if (!cur->children[c]) return false;
            cur = cur->children[c];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            if (!cur->children[c]) return false;
            cur = cur->children[c];
        }
        return true;
    }

private:
    unordered_map<char, Trie*> children;
    bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */