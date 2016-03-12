// Question: https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        int i = 0, j = 0;
        while (j < str.size()) {
            if (str[j] == ' ') {
                words.push_back(str.substr(i, j-i));
                i = j+1;
            }
            ++j;
        }
        if (j > i) {
            words.push_back(str.substr(i, j-i));
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int len = pattern.size();
        for (int i = 0; i < len; ++i) {
            char c = pattern[i];
            auto s = words[i];
            if (m1.count(c) == 0) {
                m1[c] = s;
            } else {
                if (m1[c] != s) {
                    return false;
                }
            }

            if (m2.count(s) == 0) {
                m2[s] = c;
            } else {
                if (m2[s] != c) {
                    return false;
                }
            }
        }
        return true;
    }
};
