// Question: https://leetcode.com/problems/n-queens-ii/

#include "headers.h"

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queen_pos(n, -1);
        int ans = 0;
        int current_row = 0;
        while (current_row >= 0) {
            ++queen_pos[current_row];
            while (queen_pos[current_row] < n && !check(queen_pos, current_row)) {
                ++queen_pos[current_row];
            }
            if (queen_pos[current_row] < n) {
                if (current_row == n-1) {
                    ++ans;
                } else {
                    ++current_row;
                    queen_pos[current_row] = -1;
                }
            } else {
                --current_row;
            }
        }
        return ans;
    }

private:
    bool check(vector<int>& queen_pos, int current_row) {
        for (int i = 0; i < current_row; ++i) {
            if (queen_pos[i] == queen_pos[current_row] || abs(i-current_row) == abs(queen_pos[i]-queen_pos[current_row])) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.totalNQueens(4) << endl;
    return 0;
}
