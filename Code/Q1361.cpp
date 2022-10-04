#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] > -1) inDegree[leftChild[i]] += 1;
            if (rightChild[i] > -1) inDegree[rightChild[i]] += 1;
        }
        
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i]) continue;
            
            if (root == -1) 
                root = i;
            else 
                return false;
        }
        if (root == -1) return false;
        
        vector<bool> visited(n, false);
        list<int> queue;
        queue.push_back(root);
        visited[root] = true;
        int visitNum = 1;
        while (queue.size()) {
            int cur = queue.front();
            queue.pop_front();
            if (leftChild[cur] > -1) {
                int child = leftChild[cur];
                if (visited[child]) return false;
                queue.push_back(child);
                visited[child] = true;
                visitNum++;
            }
            if (rightChild[cur] > -1) {
                int child = rightChild[cur];
                if (visited[child]) return false;
                queue.push_back(child);
                visited[child] = true;
                visitNum++;
            }
        }
        
        int i = 0;
        return visitNum == n;
    }
};