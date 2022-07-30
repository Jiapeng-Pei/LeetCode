#include "DataStructures.cpp"

class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> findLeaves(TreeNode* root) {
        postOrder(root);
        return ret;
    }

    int postOrder(TreeNode* root) {
        if (!root) return 0;
        int height = 1 + max(postOrder(root->left), postOrder(root->right));
        if (height > ret.size()) ret.push_back(vector<int>{});
        ret[height-1].push_back(root->val);
        return height;
    }
};