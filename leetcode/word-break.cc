// Question: https://leetcode.com/problems/word-break/

#include "headers.h"

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        return dp(s, wordDict);
    }

    bool dp(string s, unordered_set<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }

        vector<bool> v(s.size()+1, false);
        v[0] = true;
        unordered_set<int> dict_len;
        for (auto word : wordDict) {
            dict_len.insert(word.size());
        }

        for (int i = 0; i <= s.size(); ++i) {
            for (int j : dict_len) {
                if (j <= i) {
                    if (wordDict.count(s.substr(i-j, j)) > 0) {
                        v[i] = v[i-j];
                        if (v[i]) {
                            break;
                        }
                    }
                }
            }
        }

        return v[s.size()];
    }

    bool dfs(string s, unordered_set<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }
        int min_len, max_len;
        get_min_max(wordDict, min_len, max_len);
        queue<int> pos;
        pos.push(0);
        while (!pos.empty()) {
            int p = pos.front();
            pos.pop();
            if (p == s.size()) {
                return true;
            }
            for (int i = max_len; i >= min_len; --i) {
                if (p+i <= s.size()) {
                    if (wordDict.count(s.substr(p, i)) > 0) {
                        pos.push(p+i);
                    }
                }
            }
        }
        return false;
    }

private:
    void get_min_max(unordered_set<string>& word_dict, int& min_len, int& max_len) {
        min_len = INT_MAX;
        max_len = INT_MIN;
        for (auto word : word_dict) {
            min_len = min(min_len, (int)word.size());
            max_len = max(max_len, (int)word.size());
        }
    }
};

int main(int argc, char** argv) {
    unordered_set<string> word_dict;
    word_dict.insert("a");
    word_dict.insert("aa");
    word_dict.insert("aaa");
    word_dict.insert("aaaa");
    word_dict.insert("aaaaa");
    word_dict.insert("aaaaaa");
    word_dict.insert("aaaaaaa");
    word_dict.insert("aaaaaaaa");
    word_dict.insert("aaaaaaaaa");
    word_dict.insert("aaaaaaaaaa");
    Solution s;
    cout << s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", word_dict) << endl;
}
