/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "DataStructures.cpp"

class Solution {
public:
    vector<TreeNode*> nums;
    
    void recoverTree(TreeNode* root) {
        inOrder(root);
        TreeNode* x = nullptr, *y = nullptr;
        bool hasFirstSwapped = false;
        for (signed i = 0; i < nums.size() - 1; i++) {
            // check whether array[i] is in order
            if (nums[i]->val <= nums[i+1]->val) continue;
            y = nums[i+1];
            if (!x) 
                x = nums[i];
            else 
                break;
        }
        
        swap(x->val, y->val);
    }
    
    void inOrder(TreeNode* cur) {
        if (!cur) return;
        inOrder(cur->left);
        nums.push_back(cur);
        inOrder(cur->right);
    }
};