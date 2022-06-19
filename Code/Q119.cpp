#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret{1};
        int index = 0;
        while (index < rowIndex) {
            index++;
            vector<int> cur(index + 1, 1);
            for (int i = 1; i < cur.size() - 1; i++)
                cur[i] = ret[i-1] + ret[i];
            ret = cur;
        }

        return ret;
    }
};