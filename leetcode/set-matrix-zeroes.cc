// Question: https://leetcode.com/problems/set-matrix-zeroes/

#include "headers.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }

        int row = matrix.size(), col = matrix[0].size();
        bool first_row = false, first_col = false;
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) {
                first_col = true;
            }
        }
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                first_row = true;
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < row; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < col; ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (first_row) {
            for (int i = 0; i < col; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (first_col) {
            for (int i = 0; i < row; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{0,2,3});
    matrix.push_back(vector<int>{4,5,6});
    matrix.push_back(vector<int>{7,8,9});
    s.setZeroes(matrix);
    for (auto v : matrix) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
