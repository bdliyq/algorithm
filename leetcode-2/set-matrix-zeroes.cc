// Question: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        int first_col_flag = 0, first_row_flag = 0;

        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) {
                first_col_flag = 1;
                break;
            }
        }
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                first_row_flag = 1;
                break;
            }
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < row; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < col; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < row; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_col_flag == 1) {
            for (int i = 0; i < row; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (first_row_flag == 1) {
            for (int j = 0; j < col; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};
