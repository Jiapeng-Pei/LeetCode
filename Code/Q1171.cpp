#include <stdio.h>
#include <vector>
#include <iostream>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int nodesNum = 0;

    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        nodesNum = nodes;
        postOrder(0, parent, value);
        return nodesNum;
    }

    // pair[0] denote subtree sum, pair[1] denote subtree size.
    pair<int, int> postOrder(int cur, vector<int>& parent, vector<int>& val) {
        pair<int, int> ret(val[cur], 1);
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == cur) {
                pair<int, int> subpair = postOrder(i, parent, val);
                ret.first += subpair.first;
                ret.second += subpair.second;
            }
        }
        if (!ret.first) {
            nodesNum -= ret.second;
            ret.second = 0;
        }

        return ret;
    }
};

int main() {
    Solution sol;
    int nodes = 7;
    vector<int> parent{-1, 0, 0, 1, 2, 2, 2};
    vector<int> value{1, -2, 4, 0, -2, -1, -1};
    cout << sol.deleteTreeNodes(nodes, parent, value) << endl;
}