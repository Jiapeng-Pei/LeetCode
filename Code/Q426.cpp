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
    TreeNode* treeToDoublyList(TreeNode* root) {
        stack<TreeNode*> myStack;
        TreeNode* cur = root;
        while (cur) {
            myStack.push(cur);
            cur = cur->left;
        }
        TreeNode* retNode = myStack.top();

        while (myStack.size()) {
            TreeNode* top = myStack.top();
            myStack.pop();
            if (top->right) {
                TreeNode* cur = top->right;
                while (cur) {
                    myStack.push(cur);
                    cur = cur->left;
                }
                top->right = myStack.top();
                myStack.top()->left = top;
            }
            else if (myStack.size()) {
                top->right = myStack.top();
                myStack.top()->left = top;
            }
            else {
                top->right = retNode;
                retNode->left = top;
            }
        }

        return retNode;
    }
};

int main() {
    TreeNode n1(1), n3(3), n5(5);
    TreeNode n2(2, &n1, &n3);
    TreeNode n4(4, &n2, &n5);
    Solution sol;
    TreeNode* cur = sol.treeToDoublyList(&n4);
    do {
        cout << cur->val << ", pre: " << cur->left->val << ", next: " << cur->right->val << endl;
        cur = cur->right;
    } while (cur->val != 1);
}
