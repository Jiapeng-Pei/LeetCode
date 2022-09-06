#include "DataStructures.cpp"

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root->left && !root->right) return {root->val};
        
        vector<int> left;
        vector<int> leaves;
        vector<int> right;
        vector<int> ret;
        
        TreeNode* cur = root->left;
        while (cur && (cur->left || cur->right)) {
            left.push_back(cur->val);
            cur = cur->left ? cur->left : cur->right;
        }
        cur = root->right;
        while (cur && (cur->left || cur->right)) {
            right.push_back(cur->val);
            cur = cur->right ? cur->right : cur->left;
        }
        findLeaves(root, leaves);
        
        ret.push_back(root->val);
        for (int i : left) ret.push_back(i);
        for (int i : leaves) ret.push_back(i);
        for (auto it = right.rbegin(); it != right.rend(); it++) ret.push_back(*it);
        
        return ret;
    }
    
    void findLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }
        
        if (root->left) findLeaves(root->left, leaves);
        if (root->right) findLeaves(root->right, leaves);
    }
};