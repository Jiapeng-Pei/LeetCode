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

    int kthSmallest(TreeNode* root, int k) {
        try {
            recursive(root, k);
        } catch (string msg) {
            return stoi(msg);
        }

        return 0;
    }

    int recursive(TreeNode* cur, int rank) {
        if (!cur) return 0;
        
        int leftSize = recursive(cur->left, rank);
        if (leftSize == rank - 1) throw to_string(cur->val);
        int rightSize = recursive(cur->right, rank - leftSize - 1);
        return leftSize + rightSize + 1;
    }
};