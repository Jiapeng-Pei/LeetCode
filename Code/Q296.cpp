#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public: 
    int minTotalDistance(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows;
        vector<int> cols;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) rows.push_back(i);
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j]) cols.push_back(j);
            }
        }

        return calculateDistance(rows) + calculateDistance(cols);
    }

    int calculateDistance(vector<int> array) {
        int midVal = array[array.size() / 2];
        int ret = 0;
        for (int i : array) {
            ret += abs(midVal - i);
        }
        return ret;
    }
};