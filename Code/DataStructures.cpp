#include <stdio.h>
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>
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

struct ListNode {
int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class UnionFind {
public:
    vector<int> root;
    vector<int> rank;
    int count;
    UnionFind(int n) {
        count = n;
        for (int i = 0; i < n; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int i) {
        if (root[i] == i) return i;
        root[i] = find(root[i]);
        return root[i];
    }

    bool Union(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return false;
        if (rank[rootI] < rank[rootJ]) {
            root[rootI] = rootJ;
        } 
        else if (rank[rootI] > rank[rootJ]) {
            root[rootJ] = rootI;
        }
        else {
            root[rootI] = rootJ;
            rank[rootJ]++;
        }
        count--;
        return true;
    }
};

