// 思路 首先这个问题肯定要使用后序遍历，每个节点可以拿到它子节点的Tree的Sum值，
// 相加计算该节点要不要删掉。还需要返回一个子树的大小，用于代表子树中有多少没被
// 删掉的节点。比如返回0就是都删了。所以递归要返回两个值。
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        pair<int, int> ret = inorder(0, parent, value);
        return ret.second;
    }

    // pair[0] denotes the sum of subTree, pair[1] denotes the remaining size of subTree.
    pair<int, int> inorder(int index, vector<int>& parent, vector<int>& value) {
        pair<int, int> ret = make_pair(value[index], 1);
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == index) {
                pair<int, int> cur = inorder(i, parent, value);
                ret.first += cur.first;
                ret.second += cur.second;
            }
        }

        if (ret.first == 0) 
            ret.second = 0;
        
        return ret;
        
    }
};