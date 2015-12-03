// Question: https://leetcode.com/problems/dungeon-game/

#include "headers.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) {
            return 0;
        }

        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> mat(row, vector<int>(col, 0));
        mat[row-1][col-1] = max(1, 1 - dungeon[row-1][col-1]);
        for (int i = row-2; i >= 0; --i) {
            mat[i][col-1] = max(1, mat[i+1][col-1] - dungeon[i][col-1]);
        }
        for (int i = col-2; i >= 0; --i) {
            mat[row-1][i] = max(1, mat[row-1][i+1] - dungeon[row-1][i]);
        }
        for (int i = row-2; i >= 0; --i) {
            for (int j = col-2; j >= 0; --j) {
                mat[i][j] = max(1, min(mat[i+1][j], mat[i][j+1]) - dungeon[i][j]);
            }
        }

        return mat[0][0];
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> dungeon;
    dungeon.push_back(vector<int>{-2,-3,3});
    dungeon.push_back(vector<int>{-5,-10,1});
    dungeon.push_back(vector<int>{10,30,-5});
    cout << s.calculateMinimumHP(dungeon) << endl;
}
