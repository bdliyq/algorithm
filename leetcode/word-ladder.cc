// Question: https://leetcode.com/problems/word-ladder/

#include "headers.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            pair<string, int> step = q.front();
            q.pop();
            if (step.first == endWord) {
                return step.second;
            }
            for (int i = 0; i < step.first.size(); ++i) {
                for (int j = 0; j < alphabet.size(); ++j) {
                    if (step.first.at(i) != alphabet.at(j)) {
                        string t = step.first.substr(0, i) + alphabet.substr(j, 1) + step.first.substr(i+1);
                        if (wordList.count(t) > 0) {
                            q.push(make_pair(t, step.second+1));
                            wordList.erase(wordList.find(t));
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main(int argc, char** argv) {
    unordered_set<string> words;
    words.insert("hot");
    words.insert("dot");
    words.insert("lot");
    words.insert("dog");
    words.insert("log");
    Solution s;
    cout << s.ladderLength("hit", "cog", words) << endl;
    return 0;
}
