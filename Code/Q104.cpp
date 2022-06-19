#include <stdio.h>
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
    int ret = 0;

    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return ret;
    }

    int dfs(TreeNode* root, int depth) {
        if (!root) return 0;
        ret = max(ret, depth);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};