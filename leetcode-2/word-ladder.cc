// Question: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            string word = p.first;
            int step = p.second;
            if (word == endWord) {
                return step;
            }
            for (int w = 0; w < word.size(); ++w) {
                for (int i = 0; i < 26; ++i) {
                    char c = word[w];
                    if (c != 'a' + i) {
                        word[w] = 'a' + i;
                        if (wordList.count(word) > 0) {
                            wordList.erase(word);
                            q.push(make_pair(word, step+1));
                        }
                    }
                    word[w] = c;
                }
            }
        }
    }
};
