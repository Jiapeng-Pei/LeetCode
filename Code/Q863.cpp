/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "DataStructures.cpp"

class Solution {
public:
    vector<TreeNode*> path;
    vector<int> ret;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) {
            ret.push_back(target->val);
            return ret;
        }
        vector<TreeNode*> buffer;
        findPath(root, target, buffer);
        reverse(path.begin(), path.end());
        for (int i = 1; i < path.size() && i <= k; i++) {
            if (i == k) {
                ret.push_back(path[i]->val);
            }
            else {
                TreeNode* start = path[i-1] != path[i]->left ? path[i]->left : path[i]->right;
                findDistK(start, 1, k - i);
            }
        }
        
        findDistK(target, 0, k);
        return ret;
    }
    
    void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& buffer) {
        if (!root) return;
        
        buffer.push_back(root);
        if (root == target) {
            path = buffer;
            return;
        }
        
        findPath(root->left, target, buffer);
        findPath(root->right, target, buffer);
        
        buffer.pop_back();
    }
    
    void findDistK(TreeNode* root, int dist, int k) {
        if (!root) return;
        if (dist == k) {
            ret.push_back(root->val);
            return;
        }
        
        findDistK(root->left, dist + 1, k);
        findDistK(root->right, dist + 1, k);
    }
};