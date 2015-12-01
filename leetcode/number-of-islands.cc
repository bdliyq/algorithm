// Question: https://leetcode.com/problems/number-of-islands/

#include "headers.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0) {
            return;
        }
        if (grid[x][y] == '1') {
            grid[x][y] = '0';
            dfs(grid, x+1, y);
            dfs(grid, x-1, y);
            dfs(grid, x, y+1);
            dfs(grid, x, y-1);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        vector<vector<char>> grid;
        grid.push_back(vector<char>{'1','1','1','1','0'});
        grid.push_back(vector<char>{'1','1','0','1','0'});
        grid.push_back(vector<char>{'1','1','0','0','0'});
        grid.push_back(vector<char>{'0','0','0','0','0'});
        cout << s.numIslands(grid) << endl;
    }
    {
        vector<vector<char>> grid;
        grid.push_back(vector<char>{'0'});
        cout << s.numIslands(grid) << endl;
    }
}
