#include <vector>
#include <list>
#include <algorithm>

using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        list<TreeNode*> queue;
        bool r = false;
        
        queue.push_back(root);
        while (queue.size()) {
            int size = queue.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* cur = queue.front();
                queue.pop_front();
                level[i] = cur->val;

                if (cur->left) queue.push_back(cur->left);
                if (cur->right) queue.push_back(cur->right);
            }

            if (r) reverse(level.begin(), level.end());
            r = !r;

            ret.push_back(level);
        }

        return ret;
    }
};