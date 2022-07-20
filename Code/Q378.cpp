#include <vector>
#include <queue>

using namespace std;

class node {
public:
    int row, col, val;
    node(int r, int c, int v): row(r), col(c), val(v){};
};

struct cmp
{
    bool operator()(const node* lhs, const node* rhs){
        return lhs->val > rhs->val;
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> colIndex(n, 1);
        priority_queue<node*, vector<node*>, cmp> pq;
        for (int i = 0; i < min(n, k); i++) {
            pq.push(new node(i, 0, matrix[i][0]));
        }
        while (k > 1) {
            node* cur = pq.top();
            pq.pop();
            if (cur->col < n - 1) {
                node* toAdd = new node(cur->row, cur->col+1, matrix[cur->row][cur->col+1]);
                pq.push(toAdd);
            }
            delete cur;
            k--;
        }
        return pq.top()->val;
    }
};