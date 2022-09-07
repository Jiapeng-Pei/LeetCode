#include "DataStructures.cpp"

class Solution {
public:
    unordered_map<int, int> inorderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        return addNode(preorder, 0, 0, preorder.size());
    }

    TreeNode* addNode(vector<int>& preorder, int preBegin, int begin, int size) {
        int val = preorder[preBegin];
        TreeNode* cur = new TreeNode(val, nullptr, nullptr);
        int inorderIndex = inorderMap[val];
        int leftSize = inorderIndex - begin;
        int rightSize = size - leftSize - 1;
        if (leftSize) cur->left = addNode(preorder, preBegin + 1, begin, leftSize);
        if (rightSize) cur->right = addNode(preorder, preBegin + leftSize + 1, begin + leftSize + 1, rightSize);

        return cur;
    }
};