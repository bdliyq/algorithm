// Question: https://leetcode.com/problems/decode-ways/

#include "headers.h"

class Solution {
public:
    int numDecodings(string s) {
        return dprog(s);
    }

    int dprog(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    dp[i+1] = dp[i-1];
                } else {
                    dp[i+1] = 0;
                }
            } else {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                    dp[i+1] = dp[i] + dp[i-1];
                } else {
                    dp[i+1] = dp[i];
                }
            }
        }

        return dp[s.size()];
    }

    int recur(string s) {
        int ans = 0;
        if (s.empty()) {
            return 1;
        }
        if (s.size() == 1 && s[0] != '0') {
            return 1;
        }
        ans += recur(s.substr(1));
        if (s.size() >= 2 && (s[0] == '1' || (s[0] == '2' && s[1] >= '0' && s[1] <= '6'))) {
            ans += recur(s.substr(2));
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253") << endl;
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("100") << endl;
    return 0;
}
