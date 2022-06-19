#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>(1, 1));
        if (numRows == 1) return ret;
        ret.push_back(vector<int>(2, 1));
        // i denotes the row index, start from 0.
        // So i th row has (i+1) elements.
        for (int i = 2; i < numRows; i++) {
            vector<int> tmp(i+1, 1);
            for (int j = 1; j < tmp.size() - 1; j++) 
                tmp[j] = ret[i-1][j-1] + ret[i-1][j];
            ret.push_back(tmp);
        } 

        return ret;
    }
};