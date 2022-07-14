#include <vector>

using namespace::std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid / n][mid % n];
            
            if (val < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left != m * n && matrix[left / n][left % n] == target;
    }
    
};

