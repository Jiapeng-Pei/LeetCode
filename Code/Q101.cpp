#include <stdio.h>
#include <list>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        TreeNode* left, *right;
        list<TreeNode*> q1;
        list<TreeNode*> q2;
        q1.push_back(root->left);
        q2.push_back(root->right);
        while (q1.size() && q2.size()) {
            left = q1.front();
            q1.pop_front();
            right = q2.front();
            q2.pop_front();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            q1.push_back(left->left);
            q1.push_back(left->right);

            q2.push_back(right->right);
            q2.push_back(right->left);
        }
        return true;
    }

    bool postOrder(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right || left->val != right->val) return false;
        return postOrder(left->right, right->left) && postOrder(left->left, right->right);
    }
};