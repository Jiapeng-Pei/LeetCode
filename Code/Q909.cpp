#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int dest = n * n, ret = 0;
        list<int> deque;
        
        deque.push_back(1);
        while (deque.size()) {
            int sz = deque.size();
            ++ret;
            for (int i = 0; i < sz; i++) {
                int cur = deque.front();
                deque.pop_front();
                for (int j = 1; j <= 6; j++) {
                    int next = cur + j;
                    if (next > dest) continue;
                    
                    int r = (next-1) / n;
                    int c = (next-1) % n;
                    int rowIndex = n-1-r;
                    int colIndex = r%2==0?c:(n-1-c);
                    int& val = board[rowIndex][colIndex];
                    if (!val) continue;
                    if (val > 0) {
                        next = val;    
                    }
                    if (next == dest) return ret;
                    val = 0;
                    
                    deque.push_back(next);
                }
            }
        }
        
        return -1;
    }
};