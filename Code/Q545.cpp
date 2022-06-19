#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        
        ret.push_back(root->val);
        if (!root->left && !root->right) return ret;
        
        if (root->left) add_left(root->left, ret);
        add_leaf(root, ret);
        if (root->right) add_right(root->right, ret);
        
        return ret;
    }

    void add_left(TreeNode* root, vector<int>& ret) {
        while (root->left || root->right) {
            ret.push_back(root->val);
            if (root->left) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
    }

    void add_leaf(TreeNode* root, vector<int>& ret) {
        if (!root->left && !root->right) {
            ret.push_back(root->val);
            return;
        }
        if (root->left) add_leaf(root->left, ret);
        if (root->right) add_leaf(root->right, ret);
    }

    void add_right(TreeNode* root, vector<int>& ret) {
        vector<int> stack;
        while (root->left || root->right) {
            stack.push_back(root->val);
            if (root->right) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        for (int i = stack.size() - 1; i >= 0; i--) {
            ret.push_back(stack[i]);
        }
    }
};

int main() {
    Solution sol;
    // TreeNode n3(3), n4(4), n2(2, &n3, &n4), n1(1, nullptr, &n2);
    TreeNode n7(7), n8(8), n4(4), n5(5, &n7, &n8), n2(2, &n4, &n5), n9(9), n10(10), n6(6, &n9, &n10), n3(3, &n6, nullptr), n1(1, &n2, &n3);

    for (int i : sol.boundaryOfBinaryTree(&n1))
        cout << i << " ";
    cout << endl;

    return 0;
}