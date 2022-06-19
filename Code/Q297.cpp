#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        list<TreeNode*> queue;
        queue.push_back(root);
        
        string ret = "";
        while (queue.size()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* top = queue.front();
                queue.pop_front();

                if (!top) {
                    ret.append("n,");
                    continue;
                }
                else {
                    ret.append(to_string(top->val));
                    ret.push_back(',');
                    queue.push_back(top->left);
                    queue.push_back(top->right);
                }
            }
        }
        
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        list<TreeNode*> queue;
        int curIndex = 0;
        TreeNode* root = new TreeNode(findDigit(data, curIndex));
        
        queue.push_back(root);
        while (queue.size() && curIndex < data.size()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* top = queue.front();
                queue.pop_front();
                
                if (data[curIndex] == 'n') {
                    top->left = nullptr;
                    curIndex += 2;    
                }
                else {
                    TreeNode* tmp = new TreeNode(findDigit(data, curIndex));
                    top->left = tmp;
                    queue.push_back(tmp);
                }

                if (data[curIndex] == 'n') {
                    top->right = nullptr;
                    curIndex += 2;    
                }
                else {
                    TreeNode* tmp = new TreeNode(findDigit(data, curIndex));
                    top->right = tmp;
                    queue.push_back(tmp);
                }
            }
        }
        
        return root;
    }

    inline int findDigit(string& data, int &beginIndex) {
        int nextIndex;
        for (nextIndex = beginIndex + 1; data[nextIndex] != ','; nextIndex++);
        int ret = stoi(data.substr(beginIndex, nextIndex - beginIndex));
        beginIndex = nextIndex + 1;
        return ret;
    }
};

int main() {
    Codec sol;
    TreeNode n4(4), n5(5), n2(2), n3(3, &n4, &n5), n1(1, &n2, &n3);
    TreeNode* root = sol.deserialize("1,2,3,n,n,4,5,n,n,n,n,");
    cout << sol.serialize(root) << endl;
}
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));