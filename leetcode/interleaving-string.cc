// Question: https://leetcode.com/problems/interleaving-string/

#include "headers.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int p = s1.size();
        int q = s2.size();
        int r = s3.size();
        if (p+q != r) {
            return false;
        }

        vector<vector<bool>> dp(p+1, vector<bool>(q+1, false));
        dp[0][0] = true;
        for (int i = 1; i < p+1; ++i) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for (int i = 1; i < q+1; ++i) {
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        }

        for (int i = 1; i < p+1; ++i) {
            for (int j = 1; j < q+1; ++j) {
                if (dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                } else if (dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[p][q];
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
}
