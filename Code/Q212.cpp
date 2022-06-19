#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    string* _word = nullptr;
    Trie* children[26] = {};

    Trie() {
        for (Trie* ptr : children) ptr = nullptr;
        _word = nullptr;
    }
    
    void insert(string& word) {
        Trie* cur = this;
        for (char c : word) {
            if (!cur->children[c - 'a']) 
                cur->children[c - 'a'] = new Trie();
            cur = cur->children[c - 'a'];
        }
        cur->_word = &word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if (!board.size() || !board[0].size() || !words.size()) return ret;
        Trie* root = new Trie();
        for (string& word : words) root->insert(word);
        depthFirstSearch(board, ret, root);
        return ret;
    }

    void depthFirstSearch(vector<vector<char>>& board, vector<string>& ret, Trie* root) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited = vector(m, vector<bool>(n, false));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                dfs(board, m, n, x, y, visited, ret, root);
            }
        }
    }

    void dfs(vector<vector<char>>& board, int xSize, int ySize, int x, int y, vector<vector<bool>>& visited, vector<string>& ret, Trie* node) {
        if (x < 0 || x >= xSize || y < 0 || y >= ySize) return;
        char cur = board[x][y];
        if (visited[x][y] || !node->children[cur - 'a']) return;
        node = node->children[cur - 'a'];
        if (node->_word) {
            ret.push_back(*(node->_word));
            node->_word = nullptr;
        }
        visited[x][y] = true;
        dfs(board, xSize, ySize, x-1, y, visited, ret, node);
        dfs(board, xSize, ySize, x+1, y, visited, ret, node);
        dfs(board, xSize, ySize, x, y-1, visited, ret, node);
        dfs(board, xSize, ySize, x, y+1, visited, ret, node);
        visited[x][y] = false;
    }
    
};