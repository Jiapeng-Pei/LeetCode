#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderIterativeTraversal(TreeNode* root) {
        stack<TreeNode*> myStack;
        vector<int> ret;
        if (!root) return ret;
        
        TreeNode* cur = root;
        while (cur) {
            myStack.push(cur);
            cur = cur->left;
        }  

        while (myStack.size()) {
            TreeNode* top = myStack.top();
            myStack.pop();
            if (top->right) {
                TreeNode* cur = top->right;
                while (cur) {
                    myStack.push(cur);
                    cur = cur->left;
                }
            }
            ret.push_back(top->val);
        }

        return ret;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inOrder(ret, root);
        return ret;
    }

    void inOrder(vector<int>& ret, TreeNode* root) {
        if (!root) return;
        inOrder(ret, root->left);
        ret.push_back(root->val);
        inOrder(ret, root->right);
    }
};