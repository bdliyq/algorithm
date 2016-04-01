// Question: word-break.

// word break.
bool solve(string s, unordered_set<string> dict) {
    unordered_set<int> word_lens;
    for (auto word : dict) {
        word_lens.insert(word.size());
    }

    int len = s.size();
    vector<bool> dp(len+1, false);
    dp[0] = true;
    for (int i = 1; i <= len; ++i) {
        for (auto l : word_lens) {
            if (i >= l) {
                auto sub = s.substr(i-l, l);
                if (dict.count(sub) > 0) {
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

// word break ii.
vector<string> solve(string& s, unordered_set<string>& dict) {
    unordered_map<int, vector<string>> memo;
    return dfs(s, 0, memo, dict);
}

vector<string> dfs(string& s, int start, unordered_map<int, vector<string>>& memo, unordered_set<stirng>& dict) {
    if (memo.count(start) > 0) {
        return memo[start];
    }

    memo[start] = vector<string>();
    int i = start;
    while (i < s.size()) {
        auto sub = s.substr(start, i-start+1);
        ++i;

        if (dict.count(sub) > 0) {
            if (i == end) {
                memo[start].push_back(sub);
            } else {
                auto v = dfs(s, i, memo, dict);
                for (auto w : v) {
                    memo[start].push_back(sub + " " + w);
                }
            }
        }
    }

    return memo[start];
}
