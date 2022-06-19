#include <stdio.h>
#include <iostream>
#include <vector>

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
    bool isValidBST(TreeNode* root) {
        return inorder(root, INT64_MIN, INT64_MAX);
    }

    bool inorder(TreeNode* cur, int64_t lower, int64_t upper) {
        if (!cur) return true;
        if (cur->val <= lower || cur->val >= upper) return false;
        return inorder(cur->left, lower, cur->val) && inorder(cur->right, cur->val, upper);
    }
};