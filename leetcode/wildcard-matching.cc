// Question: https://leetcode.com/problems/wildcard-matching/

#include "headers.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        // return backtrack(s, p);
        return dprog(s, p);
    }

private:
    bool dprog(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        if (s.empty()) {
            return p.empty() || count(p.begin(), p.end(), '*') == p.size();
        }

        int row = s.size();
        int col = p.size();

        vector<vector<bool>> dp(row+1, vector<bool>(col+1, false));
        dp[0][0] = true;
        for (int i = 1; i < row+1; ++i) {
            dp[i][0] = false;
        }
        for (int j = 1; j < col+1; ++j) {
            dp[0][j] = dp[0][j-1] && (p[j-1] == '*');
        }

        for (int i = 1; i < row+1; ++i) {
            for (int j = 1; j < col+1; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
            }
        }

        return dp[row][col];
    }

    bool backtrack(string s, string p) {
        int ps = 0, pp = 0, saved_ps = -1, saved_pp = -1;
        while (ps < s.size()) {
            if (pp < p.size() && (s[ps] == p[pp] || p[pp] == '?')) {
                ++ps;
                ++pp;
            } else if (pp < p.size() && p[pp] == '*') {
                saved_ps = ps+1;
                saved_pp = pp++;
            } else if (saved_ps != -1) {
                ps = saved_ps;
                pp = saved_pp;
            } else {
                return false;
            }
        }

        string subp = p.substr(pp);
        return (count(subp.begin(), subp.end(), '*') == subp.size());
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", "?*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
}
