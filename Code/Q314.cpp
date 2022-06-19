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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // pos includes 0.
        vector<vector<int>> positive;
        vector<vector<int>> negative;
        if (!root) return positive;
        list<pair<TreeNode*, int>> que;
        que.push_back({root, 0});

        while (que.size()) {
            int levelSize = que.size();
            for (int i = 0; i < que.size(); i++) {
                TreeNode* cur = que.front().first;
                int index = que.front().second;

                if (index >= 0) {
                    if (index >= positive.size()) {
                        positive.push_back({cur->val});
                    }
                    else {
                        positive[index].push_back(cur->val);
                    }
                }
                else {
                    int j = -index - 1;
                    if (j >= negative.size()) {
                        negative.push_back({cur->val});                        
                    }
                    else {
                        negative[j].push_back(cur->val);
                    }
                }

                que.pop_front();
                if (cur->left) que.push_back({cur->left, index - 1});
                if (cur->right) que.push_back({cur->right, index + 1});
            }
        }

        reverse(negative.begin(), negative.end());
        for (vector<int>& vec : positive) negative.push_back(vec);

        return negative;
    }
};