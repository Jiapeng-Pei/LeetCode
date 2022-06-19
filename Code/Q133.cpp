#include <vector>
#include <stdio.h>
#include <unordered_map>

using namespace::std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        if (node->neighbors.size() == 0) return new Node(node->val, node->neighbors);
        unordered_map<Node*, Node*> hashMap;
        // traverse the graph, and find all the nodes in the graph.
        dfs(node, hashMap);
        return hashMap[node];
    }

    void dfs(Node* cur, unordered_map<Node*, Node*>& hashmap ) {
        if (hashmap.count(cur)) return;
        Node* newNode = new Node(cur->val);
        hashmap[cur] = newNode;
        for (int i = 0; i < cur->neighbors.size(); i++) {
            if (!hashmap.count(cur->neighbors[i])) dfs(cur->neighbors[i], hashmap);
            newNode->neighbors.push_back(hashmap[cur->neighbors[i]]);
        }
    }
};