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
    int ret = INT32_MIN;

    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        postOrder(root);
        return ret;
    }

    int postOrder(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftMax = postOrder(root->left);
        int rightMax = postOrder(root->right);
        // calculate max path length here.
        int curMaxPath = root->val;
        if (leftMax > 0) curMaxPath += leftMax;
        if (rightMax > 0) curMaxPath += rightMax;
        ret = max(curMaxPath, ret);
        return max(leftMax, rightMax) > 0 ? root->val + max(leftMax, rightMax) : root->val;
    }
};

// 1. Use postOrder traversal, get subTree's max path distance
// return: max path length containing the current node
// in the process: calculate max path 