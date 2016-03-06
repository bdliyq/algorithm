// Question: https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths(m, vector<int>(n, 0));
        paths[0][0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                paths[i][0] = paths[i-1][0];
            } else {
                paths[i][0] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                paths[0][j] = paths[0][j-1];
            } else {
                paths[0][j] = 0;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
                } else {
                    paths[i][j] = 0;
                }
            }
        }
        return paths.back().back();
    }
};
