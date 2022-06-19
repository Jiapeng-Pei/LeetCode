#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        
        list<TreeNode*> queue;
        queue.push_back(root);
        while (queue.size()) {
            int levelSize = queue.size();
            vector<int> curLevel;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* tmp = queue.front();
                queue.pop_front();
                curLevel.push_back(tmp->val);
                if (tmp->left) queue.push_back(tmp->left);
                if (tmp->right) queue.push_back(tmp->right);
            }
            ret.push_back(curLevel);
        }

        return ret;
    }
};