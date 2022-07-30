#include "DataStructures.cpp"

class Solution {
public:
    int startVal;
    int destVal;
    // This stores the reverse path from LCA to start.
    // For example, LLR means you need to move R, L, L to reach startNode.
    string startPath = "";
    string destPath = "";
    string ret = "";
    string getDirections(TreeNode* root, int startValue, int destValue) {
        this->startVal = startValue;
        this->destVal = destValue;
        postOrder(root);
        return ret;
    }

    int postOrder(TreeNode* root) {
        if (!root || ret.size()) return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        int cur = root->val == startVal || root->val == destVal ? root->val : 0;

        if (left == startVal || right == startVal) startPath.push_back('U');
        if (left == destVal) destPath.push_back('L');
        if (right == destVal) destPath.push_back('R');
        
        if (left + right + cur == startVal + destVal) {
            ret.append(startPath);
            reverse(destPath.begin(), destPath.end());
            ret.append(destPath);
            return 0;
        }

        return left + right + cur;
    }
};