#include "DataStructures.cpp"

class Solution {
public:
    int ret = 0;
    int goodNodes(TreeNode* root) {
        recursive(root, INT_MIN);
        return ret;
    }
    
    void recursive(TreeNode* cur, int val) {
        if (!cur) return;
        if (cur->val >= val) {
            ret++;
            val = cur->val;
        }
        recursive(cur->left, val);
        recursive(cur->right, val);
    }
};