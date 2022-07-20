#include "DataStructures.cpp"

class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* ret = nullptr;

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            ret = p->right;
            while (ret->left) ret = ret->left;
            return ret;
        }

        inOrder(root, p);
        return ret;        
    }

    void inOrder(TreeNode* cur, TreeNode* p) {
        if (!cur || ret) return;

        inOrder(cur->left, p);
        if (prev == p) ret = cur;
        prev = cur;
        inOrder(cur->right, p);
    }
};