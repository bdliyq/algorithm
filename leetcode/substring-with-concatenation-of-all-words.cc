// Question: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include "headers.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) {
            return ans;
        }

        unordered_map<string, int> word_dict;
        for (auto w : words) {
            word_dict[w]++;
        }

        int word_len = words[0].size();
        int offset = word_len * ((int)words.size() - 1);
        int str_len = s.size();
        int start = -1;
        unordered_map<string, vector<int>> word_pos;

        for (int i = 0; i < word_len; ++i) {
            start = -1;
            word_pos.clear();
            for (int j = i; j <= str_len - word_len; j += word_len) {
                string candidate = s.substr(j, word_len);
                if (word_dict.count(candidate) == 0) {
                    start = -1;
                    word_pos.clear();
                } else {
                    if (start == -1) {
                        start = j;
                    }
                    if (word_pos.count(candidate) == 0) {
                        word_pos[candidate] = vector<int>();
                    }
                    word_pos[candidate].push_back(j);
                    if (word_pos[candidate].size() > word_dict[candidate]) {
                        if (word_pos[candidate][0] >= start) {
                            start = word_pos[candidate][0] + word_len;
                        }
                        word_pos[candidate].erase(word_pos[candidate].begin());
                    }
                    if (offset == j - start) {
                        ans.push_back(start);
                        start += word_len;
                    }
                }
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> words{"foo", "bar"};
    vector<int> ans = s.findSubstring("barfoothefoobarman", words);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
