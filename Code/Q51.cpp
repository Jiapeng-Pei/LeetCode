#include <vector>
#include <stdio.h>
#include <string>

using namespace::std;

class Solution {
public:
    vector<vector<string>> ret;
    string rowStr = "";
    int size = 0;

    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<bool> colCheck(size, true);
        vector<bool> diagOneCheck(2*size - 1 ,true);
        vector<bool> diagTwoCheck(2*size - 1 ,true);
        vector<int> quenesIndex(size, -1);
        for (int i = 0; i < size; i++) rowStr.push_back('.');
        recursive(colCheck, diagOneCheck, diagTwoCheck, quenesIndex, 0);
        return ret;
    }

    void recursive(vector<bool>& colCheck, vector<bool>& diagOneCheck, vector<bool>& diagTwoCheck, vector<int>& quenesIndex, int rowIndex) {
        if (rowIndex == size) {
            addToRet(quenesIndex);
            return;
        }

        for (int colIndex = 0; colIndex < size; colIndex++) {
            int diagOneIndex = colIndex - rowIndex + size - 1;
            int diagTwoIndex = colIndex + rowIndex;
            if (colCheck[colIndex] && diagOneCheck[diagOneIndex] && diagTwoCheck[diagTwoIndex]) {
                quenesIndex[rowIndex] = colIndex;
                colCheck[colIndex] = false;
                diagOneCheck[diagOneIndex] = false;
                diagTwoCheck[diagTwoIndex] = false;
                recursive(colCheck, diagOneCheck, diagTwoCheck, quenesIndex, rowIndex+1);
                quenesIndex[rowIndex] = -1;
                colCheck[colIndex] = true;
                diagOneCheck[diagOneIndex] = true;
                diagTwoCheck[diagTwoIndex] = true;
            }
        }
    }

    void addToRet(vector<int>& quenesIndex) {
        vector<string> content(size, rowStr);
        for (int i = 0; i < size; i++)
           content[i][quenesIndex[i]] = 'Q'; 
        
        ret.push_back(content);
    }
};

// at every recursive call, the entry is the current row. we choice a position to put a queen.
// after we choose a positon, we block the whole row, whole column and the dialog.

// Start from each row, Recursion on rowNum rows.
// Base case : rowNum = 0;
// Recursive case : rowNum < size;
// return case : rowNum = size.
// Time complexity: 
