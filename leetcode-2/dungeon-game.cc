// Question: https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) {
            return 0;
        }

        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> life(row, vector<int>(col, 0));
        life[row-1][col-1] = dungeon.back().back() > 0 ? 1 : 1 - dungeon.back().back();
        for (int i = row-2; i >= 0; --i) {
            life[i][col-1] = max(1, life[i+1][col-1] - dungeon[i][col-1]);
        }
        for (int j = col-2; j >= 0; --j) {
            life[row-1][j] = max(1, life[row-1][j+1] - dungeon[row-1][j]);
        }

        for (int i = row-2; i >= 0; --i) {
            for (int j = col-2; j >= 0; --j) {
                life[i][j] = min(max(1, life[i+1][j] - dungeon[i][j]), max(1, life[i][j+1] - dungeon[i][j]));
            }
        }
        return life[0][0];
    }
};
