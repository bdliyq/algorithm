// Question: https://leetcode.com/problems/spiral-matrix/

#include "headers.h"

void print_vec(vector<int>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }

        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0, bottom = row-1, left = 0, right = col-1;
        vector<int> ans;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            ++top;

            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            --right;

            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                --bottom;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> mat;
    mat.push_back(vector<int>{2});
    mat.push_back(vector<int>{3});
    mat.push_back(vector<int>{4});
    // mat.push_back(vector<int>{4,5,6});
    // mat.push_back(vector<int>{7,8,9});
    auto ans = s.spiralOrder(mat);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
