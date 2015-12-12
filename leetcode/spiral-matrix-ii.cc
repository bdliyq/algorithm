// Question: https://leetcode.com/problems/spiral-matrix-ii/

#include "headers.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return vector<vector<int>>();
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0, left = 0, down = n-1, right = n-1, num = 1;
        while (left <= right && top <= down) {
            for (int i = left; i <= right; ++i) {
                ans[top][i] = num++;
            }
            ++top;
            for (int i = top; i <= down; ++i) {
                ans[i][right] = num++;
            }
            --right;
            for (int i = right; i >= left; --i) {
                ans[down][i] = num++;
            }
            --down;
            for (int i = down; i >= top; --i) {
                ans[i][left] = num++;
            }
            ++left;
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    auto ans = s.generateMatrix(3);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
