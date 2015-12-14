// Question: https://leetcode.com/problems/range-sum-query-2d-immutable/

#include "headers.h"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        C.resize(row+1, vector<int>(col+1, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                C[i+1][j+1] = matrix[i][j] + C[i][j+1] + C[i+1][j] - C[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (C.empty() || C[0].empty()) {
            return 0;
        }
        return C[row2+1][col2+1] - C[row2+1][col2] - C[row1][col2+1] + C[row1][col1];
    }

private:
    vector<vector<int>> C;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
