#include <vector>

using namespace std;

class DetectSquares {
public:
    vector<vector<int>> plane;
    
    DetectSquares() {
        plane = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        plane[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        signed x = point[0], y = point[1];
        signed up, down, left, right;
        up = down = y;
        left = right = x;
        
        int ret = 0;
        while (true) {
            bool l = --left >= 0, r = ++right <= 1000, d = --down >= 0, u = ++up <= 1000;
            if (l && d) ret += plane[left][y] * plane[x][down] * plane[left][down];
            if (l && u) ret += plane[left][y] * plane[x][up] * plane[left][up];
            if (r && d) ret += plane[right][y] * plane[x][down] * plane[right][down];
            if (r && u) ret += plane[right][y] * plane[x][up] * plane[right][up];

            if (!l && !r && !d && !u) break;
        }
        
        return ret;
    }
};
