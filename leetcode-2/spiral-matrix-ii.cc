// Question: https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n-1, top = 0, down = n-1;
        int num = 1;
        while (left <= right && top <= down) {
            for (int i = left; i <= right; ++i) {
                ans[top][i] = num++;
            }
            ++top;
            for (int i = top; i <= down; ++i) {
                ans[i][right] = num++;
            }
            --right;
            if (top <= down) {
                for (int i = right; i >= left; --i) {
                    ans[down][i] = num++;
                }
                --down;
            }
            if (left <= right) {
                for (int i = down; i >= top; --i) {
                    ans[i][left] = num++;
                }
                ++left;
            }
        }
        return ans;
    }
};
