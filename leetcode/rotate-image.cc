// Question: https://leetcode.com/problems/rotate-image/

#include "headers.h"

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
        for (int i = 0; i < size/2; ++i) {
            for (int j = 0; j < size; ++j) {
                swap(matrix[j][i], matrix[j][size-i-1]);
            }
        }
    }
private:
    void swap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1,2,3});
    matrix.push_back(vector<int>{4,5,6});
    matrix.push_back(vector<int>{7,8,9});
    s.rotate(matrix);
    for (auto v : matrix) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
