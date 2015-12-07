// Question: https://leetcode.com/problems/word-break-ii/

#include "headers.h"

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<int, vector<string>> memo;
        return helper(s, 0, s.size(), wordDict, memo);
    }

private:
    vector<string> helper(string s, int start, int end, unordered_set<string>& dict, unordered_map<int, vector<string>>& memo) {
        if (memo.count(start) > 0) {
            return memo[start];
        }

        memo[start] = vector<string>();
        int current = start;
        while (current < end) {
            string subs = s.substr(start, current-start+1);
            current++;
            if (dict.count(subs) > 0) {
                if (current == end) {
                    memo[start].push_back(subs);
                } else {
                    auto m = helper(s, current, end, dict, memo);
                    for (auto i : m) {
                        memo[start].push_back(subs + " " + i);
                    }
                }
            }
        }
        return memo[start];
    }
};

int main(int argc, char** argv) {
    Solution s;
    string sd[] = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> dict(sd, sd+5);
    vector<string> ans = s.wordBreak("catsanddog", dict);
    for (auto s : ans) {
        cout << s << endl;
    }
    return 0;
}
