// Question: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include "headers.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix.at(0).size() == 0) {
            return false;
        }

        int row = matrix.size();
        int col = matrix.at(0).size();

        int irow = 0;
        int jcol = col-1;
        while (irow < row && jcol >= 0) {
            if (matrix[irow][jcol] > target) {
                --jcol;
            } else if (matrix[irow][jcol] < target) {
                ++irow;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1,   4,  7, 11, 15});
    matrix.push_back(vector<int>{2,   5,  8, 12, 19});
    matrix.push_back(vector<int>{3,   6,  9, 16, 22});
    matrix.push_back(vector<int>{10, 13, 14, 17, 24});
    matrix.push_back(vector<int>{18, 21, 23, 26, 30});
    Solution s;
    cout << s.searchMatrix(matrix, 5) << endl;
    cout << s.searchMatrix(matrix, 20) << endl;
    return 0;
}
