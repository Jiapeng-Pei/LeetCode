#include <stdio.h>
#include <string>

using namespace std;

class Trie {
public:
    bool isEnd;
    Trie* children[26] = {};

    Trie() {
        for (Trie* ptr : children) ptr = nullptr;
        isEnd = false;
    }
    
    void insert(string& word) {
        Trie* cur = this;
        for (char c : word) {
            if (!cur->children[c - 'a']) 
                cur->children[c - 'a'] = new Trie();
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
};

class WordDictionary {
public:
    Trie* root;
    
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return recursiveSearch(word, 0, root);
    }

    bool recursiveSearch(string& word, int index, Trie* cur) {
        // 1. current index of word is a character 2. current index of word is a .;
        if (index == word.size() && cur->isEnd) return true;
        char c = word[index];
        if (c != '.') {
            return cur->children[c - 'a'] && recursiveSearch(word, index+1, cur->children[c - 'a']);
        }
        else {
            for (int i = 0; i < 26; i++) {
                if (cur->children[i] && recursiveSearch(word, index+1, cur->children[i])) return true;
            }
            return false;
        }
    }
};

    // bool recursiveSearch(string& word, int index, Trie* cur) {
    //     // 1. current index of word is a character 2. current index of word is a .;
    //     if (index == word.size() && cur->isEnd) return true;
        
    //     while (index < word.size() && word[index] != '.') {
    //         char c = word[index];
    //         if (!cur->children[c - 'a']) return false;
    //         cur = cur->children[c - 'a'];
    //         index++;
    //     }
        
    //     // reach the end of word
    //     if (index == word.size() && cur->isEnd) return true;
        
    //     // meet .
    //     for (int i = 0; i < 26; i++) {
    //         if (cur->children[i] && recursiveSearch(word, index+1, cur->children[i])) return true;
    //     }
        
    //     return false;
    // }