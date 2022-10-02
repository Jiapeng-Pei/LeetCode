#include "DataStructures.cpp"

class Solution {
public:
    pair<TreeNode*, int> xInfo, yInfo;
    int x, y;

    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        preOrder(root, nullptr, 1);
        return xInfo.second == yInfo.second && (xInfo.first != yInfo.first);
    }
    
    void preOrder(TreeNode* root, TreeNode* parent, int depth) {
        if (!root) return;
        if (root->val == x) xInfo = {parent, depth};
        if (root->val == y) yInfo = {parent, depth};
        
        preOrder(root->left, root, depth+1);
        preOrder(root->right, root, depth+1);
    }
};