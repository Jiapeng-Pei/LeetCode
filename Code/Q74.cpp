#include <vector>

using namespace::std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        vector<int> firstCol;
        for (int i = 0; i < m; i++) firstCol.push_back(matrix[i][0]);
        int row = binarySearch(firstCol, target);
        if (row < matrix.size() && matrix[row][0] == target) return true;
        row--;
        int col = binarySearch(matrix[row], target);
        return matrix[row][col] == target;
    }

    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int row = 0, col = matrix[0].size() - 1;
    //     while (row < matrix.size() && col > -1) {
    //         int cur = matrix[row][col];
    //         if (cur == target) return true;
    //         else if (cur > target) col--;
    //         else row++;
    //     }

    //     return false;
    // }

    // find the first element which value <= target.
    int binarySearch(vector<int>& array, int target) {
        if (array.size() == 1) return 0;
        int left = 0, right = array.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (array[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

