#include <stdio.h>
#include <vector>
#include "DataStructures.cpp"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return addNode(preorder, inorder, preorder.size(), 0, 0);
    }

    TreeNode* addNode(vector<int>& preorder, vector<int>& inorder, int treeSize, int preStart, int inStart) {
        int root = preorder[preStart];
        TreeNode* cur = new TreeNode(root, nullptr, nullptr);
        int rootIndex = inStart;
        for (; inorder[rootIndex] != root && rootIndex < treeSize + inStart; rootIndex++); 
        int leftSize = rootIndex - inStart;
        int rightSize = treeSize - leftSize - 1;
        if (leftSize) cur->left = addNode(preorder, inorder, leftSize, preStart + 1, inStart);
        if (rightSize) cur->right = addNode(preorder, inorder, rightSize, preStart + leftSize + 1, inStart + leftSize + 1);

        return cur;
    }
};