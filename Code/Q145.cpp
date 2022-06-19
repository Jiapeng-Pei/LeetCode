#include <vector>
#include <stdio.h>

using namespace std;

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postOrder(root, ret);
        return ret;
    }

    void postOrder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        postOrder(root->left, nums);
        postOrder(root->right, nums);
        nums.push_back(root->val);
    }
};