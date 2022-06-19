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

    void recursive(Node* cur, Node* next) {
        cur->next = next;
        if (!cur->left) return;

        recursive(cur->right, next ? next->left : nullptr);
        recursive(cur->left, cur->right);
    }
};