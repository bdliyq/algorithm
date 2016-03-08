// Question: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }

        int size = matrix.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size/2; ++j) {
                swap(matrix[i][j], matrix[i][size-1-j]);
            }
        }
    }
};
