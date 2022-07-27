#include "DataStructures.cpp"

class Solution {
public:
    TreeNode* ret = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        postOrder(root, p, q);

        return ret;
    }

    int postOrder(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == nullptr || ret) return 0;
        int left = postOrder(cur->left, p, q);
        int right = postOrder(cur->right, p, q);
        int root = cur == p || cur == q;

        if (left + right + root == 2) {
            ret = cur;
            return 0;
        }
        else 
            return left + right + root;
        
    }
};