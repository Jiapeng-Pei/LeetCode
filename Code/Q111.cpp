#include <stdio.h>
#include <climits>
#include <algorithm>

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
    int ret = INT_MAX;

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        recursive(root, 1);
        return ret;
    }

    void recursive(TreeNode* root, int depth) {
        if (depth >= ret) return;
        if (root->left == nullptr && root->right == nullptr) {
            ret = min(ret, depth);
            return;
        }
        if (root->left) recursive(root->left, depth + 1);
        if (root->right) recursive(root->right, depth + 1);
    }
};