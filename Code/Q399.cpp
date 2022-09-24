#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class node {
public:
    vector<pair<node*, double>> adj;
    double val = 0;
        
    void addEdge(node* to, double val) {
        adj.push_back({to, val});
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, node*> map;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string str1 = equations[i][0], str2 = equations[i][1];
            if (!map.count(str1)) map[str1] = new node();
            if (!map.count(str2)) map[str2] = new node();
            map[str1]->addEdge(map[str2], values[i]);
            map[str2]->addEdge(map[str1], 1.0 / values[i]);
        }
        
        vector<double> ret;
        
        for (int i = 0; i < queries.size(); i++) {
            string str1 = queries[i][0], str2 = queries[i][1];
            if (!map.count(str1) || !map.count(str2)) {
                ret.push_back(-1);
            } 
            else if (str1 == str2) {
                ret.push_back(1);
            }
            else {
                double val = bfs(map, map[str1], map[str2]);
                for (auto p : map) p.second->val = 0;
                ret.push_back(val);
            }
        }
        
        return ret;
    }
    
    double bfs(unordered_map<string, node*>& map, node* begin, node* end) {
        list<node*> deque;
        begin->val = 1;
        deque.push_back(begin);
        while (deque.size()) {
            node* cur = deque.front();
            deque.pop_front();
            for (auto p : cur->adj) {
                node* next = p.first;
                if (next->val) continue;
                next->val = cur->val * p.second;
                if (next == end) return next->val;
                deque.push_back(next);
            }
        }
        
        return -1;
    }
};