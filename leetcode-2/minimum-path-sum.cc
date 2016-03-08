// Question: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> min_sum(row, vector<int>(col, INT_MAX));
        min_sum[0][0] = grid[0][0];
        for (int i = 1; i < row; ++i) {
            min_sum[i][0] = min_sum[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < col; ++j) {
            min_sum[0][j] = min_sum[0][j-1] + grid[0][j];
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                min_sum[i][j] = min(min_sum[i-1][j], min_sum[i][j-1]) + grid[i][j];
            }
        }
        return min_sum.back().back();
    }
};
