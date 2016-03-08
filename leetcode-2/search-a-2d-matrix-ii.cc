// Question: https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        int irow = 0, icol = col-1;
        while (irow < row && icol >= 0) {
            if (target == matrix[irow][icol]) {
                return true;
            } else if (target > matrix[irow][icol]) {
                ++irow;
            } else {
                --icol;
            }
        }
        return false;
    }
};
