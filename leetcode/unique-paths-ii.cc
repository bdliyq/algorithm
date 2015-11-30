// Question: https://leetcode.com/problems/unique-paths-ii/

#include "headers.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> steps(row, vector<int>(col, 0));
        steps[0][0] = 1;
        for (int i = 1; i < row; ++i) {
            if (obstacleGrid[i][0] == 0 && steps[i-1][0] == 1) {
                steps[i][0] = 1;
            }
        }
        for (int i = 1; i < col; ++i) {
            if (obstacleGrid[0][i] == 0 && steps[0][i-1] == 1) {
                steps[0][i] = 1;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    steps[i][j] = steps[i][j-1] + steps[i-1][j];
                }
            }
        }
        return steps[row-1][col-1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> grid;
    grid.push_back(vector<int>{0,0,0});
    grid.push_back(vector<int>{0,1,0});
    grid.push_back(vector<int>{0,0,0});
    cout << s.uniquePathsWithObstacles(grid) << endl;
    return 0;
}
