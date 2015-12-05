// Question: https://leetcode.com/problems/perfect-squares/

#include "headers.h"

void print_vec(const vector<int>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = i*i; j <= n; j*=j) {
                dp[j] = 1;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dp[i] == INT_MAX) {
                for (int j = 1; j*j <= i; ++j) {
                    int diff = i-j*j;
                    dp[i] = min(dp[i], dp[diff]+1);
                }
            }
        }

        return dp[n];
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numSquares(9975) << endl;
}
