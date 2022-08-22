#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class BSTIterator {
// public:
//     vector<int> array;
//     int index = 0;

//     BSTIterator(TreeNode* root) {
//         inOrder(root);
//     }

//     void inOrder(TreeNode* cur) {
//         if (!cur) return;
//         inOrder(cur->left);
//         array.push_back(cur->val);
//         inOrder(cur->right);
//     }
    
//     int next() {
//         return array[index++];
//     }
    
//     bool hasNext() {
//         return index < array.size();
//     }
// };

class BSTIterator {
public:
    list<TreeNode*> myStack;

    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            myStack.push_back(cur);
            cur = cur->left;
        }        
    }
    
    int next() {
        TreeNode* top = myStack.back();
        myStack.pop_back();
        if (top->right) {
            TreeNode* cur = top->right;
            while (cur) {
                myStack.push_back(cur);
                cur = cur->left;
            }
        }
        return top->val;
    }
    
    bool hasNext() {
        return myStack.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
