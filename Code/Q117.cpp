#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace::std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        recursive(root, nullptr);
        return root;
    }

    void iterative(Node* root) {
        while (root) {
            Node* dummy = new Node(-1);
            Node* curChild = dummy;
            while (root) {
                if (root->left) {
                    curChild->next = root->left;
                    curChild = curChild->next;
                }
                if (root->right) {
                    curChild->next = root->right;
                    curChild = curChild->next;
                }
                root = root->next;
            }
            root = dummy->next;
        }
    }

    void recursive(Node* cur, Node* next) {
        cur->next = next;

        // arrive at leaf node, stop
        if (!cur->left && !cur->right) return;
        
        // find next node for current node's children nodes.  
        Node* nextChild = next ? (next->left ? next->left : next->right) : nullptr;

        //      1 
        //    2   3
        //   n n 4 5
        // for above situation, we need to return 4. Following while loop find 
        // the next node for its childern.
        while (!nextChild && next) {
            next = next->next;
            nextChild = next ? (next->left ? next->left : next->right) : nullptr;
        } 
        if (cur->right) 
            recursive(cur->right, nextChild);
        if (cur->left) 
            recursive(cur->left, cur->right ? cur->right : nextChild);
        
    }
};