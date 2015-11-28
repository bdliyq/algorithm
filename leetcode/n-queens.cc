// Question: https://leetcode.com/problems/n-queens/

#include "headers.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queen_pos(n, -1);
        vector<vector<string>> ans;
        int current_row = 0;
        while (current_row >= 0) {
            ++queen_pos[current_row];
            while (queen_pos[current_row] < n && check(queen_pos, current_row) == false) {
                ++queen_pos[current_row];
            }
            if (queen_pos[current_row] < n) {
                if (current_row == n-1) {
                    ans.push_back(vector<string>());
                    for (auto pos : queen_pos) {
                        ans.back().push_back(string(pos,'.') + string(1,'Q') + string(n-pos-1,'.'));
                    }
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
    vector<vector<string>> ans = s.solveNQueens(4);
    for (auto a : ans) {
        for (auto v : a) {
            cout << v << endl;
        }
        cout << "#####" << endl;
    }
    return 0;
}
