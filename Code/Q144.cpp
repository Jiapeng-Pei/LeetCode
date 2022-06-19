#include <vector>
#include <stdio.h>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//    2
//  1   3
//    4    

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        list<TreeNode*> stack;
        stack.push_back(root);
        while (stack.size()) {
            TreeNode* top = stack.back();
            stack.pop_back();
            if (top != nullptr) {
                ret.push_back(top->val);
                stack.push_back(top->right);
                stack.push_back(top->left);
            }
        }

        return ret;
    }

    void preOrder(TreeNode* root, vector<int>& ret) {
        if (!root) return;
        ret.push_back(root->val);
        preOrder(root->left, ret);
        preOrder(root->right, ret);
    }
};