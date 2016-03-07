// Question: https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_set<int> len_dict;
        for (auto word : wordDict) {
            len_dict.insert(word.size());
        }

        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        for (int i = 0; i <= len; ++i) {
            for (auto l : len_dict) {
                if (i >= l) {
                    string sub = s.substr(i-l, l);
                    if (wordDict.count(sub) > 0) {
                        dp[i] = dp[i-l];
                        if (dp[i]) {
                            break;
                        }
                    }
                }
            }
        }

        return dp.back();
    }
};
