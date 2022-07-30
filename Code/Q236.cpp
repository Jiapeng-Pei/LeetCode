#include "DataStructures.cpp"

// 这个题的精妙之处在于寻找两个子节点的同时返回有可能的公共父节点。注意在过程中及时更新返回值的问题。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        else return left ? left : right;
    }
};

// 1. p, q互不为对方的子树：最后找到公共祖先的条件就是一边一个
// 2. p, q其中一个为对方的子树：那么最后的祖先就是p/q