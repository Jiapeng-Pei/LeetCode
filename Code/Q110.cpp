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
    bool isBalanced(TreeNode* root) {
        return postOrder(root) != -1;
    }

    int postOrder(TreeNode* root) {
        if (!root) return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        if (left == -1 || right == -1 || left - right > 1 || left - right < -1) 
            return -1;
        return max(left, right) + 1;        
    }
};