// Question: https://leetcode.com/problems/palindrome-partitioning-ii/

#include "headers.h"

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> dp(len+1, 0);
        vector<bool> is_pal(len, false);
        dp[0] = -1;
        for (int i = 0; i < len; ++i) {
            dp[i+1] = dp[i] + 1;
        }

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == i) {
                    is_pal[j] = true;
                } else if (j == i-1) {
                    is_pal[j] = s[j] == s[i];
                } else {
                    is_pal[j] = is_pal[j+1] && s[j] == s[i];
                }
                if (is_pal[j]) {
                    dp[i+1] = min(dp[i+1], dp[j] + 1);
                }
            }
        }

        return dp[len];
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.minCut("aab") << endl;
    cout << s.minCut("") << endl;
    cout << s.minCut("a") << endl;
    cout << s.minCut("aabcbaa") << endl;
    cout << s.minCut("aabcbad") << endl;
    return 0;
}
