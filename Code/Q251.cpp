#include <vector>

using namespace std;

class Vector2D {
public:
    unsigned i = 0, j = 0;
    vector<vector<int>> twoDimVector;
    Vector2D(vector<vector<int>>& vec) {
        twoDimVector = vec;
    }
    
    int next() {
        if (!hasNext()) throw new exception;
        return twoDimVector[i][j++];
    }
    
    bool hasNext() {
        while (i < twoDimVector.size() && j == twoDimVector[i].size()) {
            i++;
            j = 0;
        }
        return i < twoDimVector.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */