// Question: https://leetcode.com/problems/search-a-2d-matrix/

#include "headers.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int row = matrix.size(), col = matrix[0].size();
        int low = 0, high = row * col - 1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            int i = mid / col;
            int j = mid % col;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1,   3,  5,  7});
    matrix.push_back(vector<int>{10, 11, 16, 20});
    matrix.push_back(vector<int>{23, 30, 34, 50});
    matrix.push_back(vector<int>{123, 130, 134, 150});
    cout << s.searchMatrix(matrix, 3) << endl;
    cout << s.searchMatrix(matrix, 34) << endl;
    cout << s.searchMatrix(matrix, 13) << endl;
    cout << s.searchMatrix(matrix, 200) << endl;
    cout << s.searchMatrix(matrix, 0) << endl;
}
