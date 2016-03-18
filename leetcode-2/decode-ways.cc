// https://leetcode.com/problems/decode-ways/

#include "headers.h"

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        int len = s.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '0') {
                if (i == 0 || (s[i-1] != '1' && s[i-1] != '2')) {
                    dp[i+1] = 0;
                } else {
                    dp[i+1] = dp[i-1];
                }
            } else {
                if (s[i-1] == '1' || (s[i-1] == '2' && (s[i] >= '0' && s[i] <= '6'))) {
                    dp[i+1] = dp[i] + dp[i-1];
                } else {
                    dp[i+1] = dp[i];
                }
            }
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numDecodings("0") << endl;
}
