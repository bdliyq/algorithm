// Question: https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> qpos(n, -1);
        int row = 0;
        int ans = 0;
        while (row >= 0) {
            ++qpos[row];
            while (qpos[row] < n && !check(qpos, row)) {
                ++qpos[row];
            }
            if (qpos[row] < n) {
                if (row == n-1) {
                    ++ans;
                } else {
                    ++row;
                    qpos[row] = -1;
                }
            } else {
                --row;
            }
        }
        return ans;
    }

    bool check(vector<int>& qpos, int row) {
        for (int i = 0; i < row; ++i) {
            if (qpos[i] == qpos[row] || abs(i-row) == abs(qpos[i]-qpos[row])) {
                return false;
            }
        }
        return true;
    }
};
