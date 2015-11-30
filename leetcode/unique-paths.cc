// Question: https://leetcode.com/problems/unique-paths/

#include "headers.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> steps(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            steps[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            steps[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                steps[i][j] = steps[i-1][j] + steps[i][j-1];
            }
        }
        return steps[m-1][n-1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.uniquePaths(1, 10) << endl;
}
