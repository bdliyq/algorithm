// Question: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row * col - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int j = mid % col;
            int i = (mid - j) / col;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
