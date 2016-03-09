// Question: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for (int x = 0; x < row; ++x) {
            for (int y = 0; y < col; ++y) {
                if (grid[x][y] == '1') {
                    ans += 1;
                    helper(grid, x, y, row, col);
                }
            }
        }

        return ans;
    }

    void helper(vector<vector<char>>& grid, int x, int y, int row, int col) {
        if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == '1') {
            grid[x][y] = '*';
            vector<int> x_delta{0,1,0,-1};
            vector<int> y_delta{1,0,-1,0};
            for (int i = 0; i < 4; ++i) {
                helper(grid, x+x_delta[i], y+y_delta[i], row, col);
            }
        }
    }
};
