class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    // TreeNode* encode(Node* root) {
    //     if(!root) return NULL;
    //     TreeNode* newRoot = new TreeNode(root->val);
    //     vector<Node*> childern = newRoot->childern;

    //     if (!childern.size()) 
    //         return newRoot;
    //     else {
    //         newRoot->left = encode(children[0]);
    //         if (children.size() == 1) 
    //             return newRoot;
    //         TreeNode* cur = newRoot->left;
    //         for (int i = 1; i < children.size(); i++) {
    //             cur->right = encode(children[i]);
    //             cur = cur->right;
    //         }
    //     }

    //     return newRoot;
    // }

    TreeNode* encode(Node* root) {
        if (!root) return NULL;
        // initialize a new TreeNode cur
        // if cur doesn't have any children, return
        // cur->left = cur.children[0]
        // if cur has only one child, then return
        // else making(recursive call encode) every other children as the direct right child of the first child
        // return cur
    }

    // Decodes your binary tree to an n-ary tree.
    // Node* decode(TreeNode* root) {
    //     if (!root)
    //         return nullptr;
    //     Node* newRoot = new Node(root->val);
    //     if (root->left == nullptr)
    //         return newRoot;
    //     else {
    //         TreeNode* cur = root->left;
    //         while (cur) {
    //             newRoot->childern.push_back(decode(cur));
    //             cur = cur->right;
    //         }
    //     }
    // }
    
    Node* decode(TreeNode* root) {
        // if root is nullptr, return nullptr
        // curNode = Node(root)
        // if root doesn't have left childern, return root as new node
        // else making every child node in its right subtree as the direct child node of cur node.
        // return curNode
        // so actually there root has right subTree, but it has been handled by its father. 
        // So we don't need to care about it in current recursion.
    }
};
