// Question: https://leetcode.com/problems/word-ladder-ii/

#include "headers.h"

class Solution {
public:
    vector<vector<string>> findLadders(string begin, string end, unordered_set<string>& dict) {
        dict.insert(end);
        unordered_map<string, vector<string>> graph;

        unordered_map<string, int> dist;
        bfs(begin, end, dict, graph, dist);

        vector<string> path;
        vector<vector<string>> ans;
        dfs(begin ,end, graph, dist, path, ans);

        return ans;
    }

private:
    void get_neighbors(string word, unordered_set<string>& dict, vector<string>& neighbors) {
        for (int i = 0; i < word.size(); ++i) {
            string next = word;
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != word[i]) {
                    next[i] = c;
                    if (dict.count(next) > 0) {
                        neighbors.push_back(next);
                    }
                    next[i] = word[i];
                }
            }
        }
    }
    void bfs(string begin, string end, unordered_set<string>& dict, unordered_map<string, vector<string>>& graph, unordered_map<string, int>& dist) {
        queue<string> q;
        q.push(begin);
        dist[begin] = 0;
        while (!q.empty()) {
            int cnt = q.size();
            bool found = false;
            for (int i = 0; i < cnt; ++i) {
                string word = q.front();
                q.pop();
                int distance = dist[word];
                vector<string> neighbors;
                get_neighbors(word, dict, neighbors);
                for (string nei : neighbors) {
                    graph[word].push_back(nei);
                    if (dist.count(nei) == 0) {
                        dist[nei] = distance + 1;
                        if (nei == end) {
                            found = true;
                        } else {
                            q.push(nei);
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
        }
    }
    void dfs(string begin,
            string end,
            unordered_map<string, vector<string>>& graph,
            unordered_map<string, int>& dist,
            vector<string>& path,
            vector<vector<string>>& ans) {
        path.push_back(begin);
        if (begin == end) {
            ans.push_back(path);
        } else {
            for (string next : graph[begin]) {
                if (dist[next] == dist[begin] + 1) {
                    dfs(next, end, graph, dist, path, ans);
                }
            }
        }
        path.pop_back();
    }

// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
//         wordList.insert(endWord);
//         vector<string> path;
//         vector<vector<string>> ans;
//         helper(beginWord, endWord, wordList, path, ans);
//         return ans;
//     }
//
// private:
//     void helper(string begin, string end, unordered_set<string>& dict, vector<string>& path, vector<vector<string>>& ans) {
//         path.push_back(begin);
//
//         if (begin == end) {
//             if (ans.empty()) {
//                 ans.push_back(path);
//             } else {
//                 if (ans.back().size() > path.size()) {
//                     ans.clear();
//                     ans.push_back(path);
//                 } else if (ans.back().size() == path.size()) {
//                     ans.push_back(path);
//                 }
//             }
//         } else {
//             if (ans.empty() || path.size() < ans.back().size()) {
//                 for (int j = 0; j < begin.size(); ++j) {
//                     for (int i = 0; i < 26; ++i) {
//                         char c = 'a' + i;
//                         if (begin[j] != c) {
//                             string newbegin = begin;
//                             newbegin.replace(j, 1, 1, c);
//                             if (dict.count(newbegin) > 0) {
//                                 dict.erase(newbegin);
//                                 helper(newbegin, end, dict, path, ans);
//                                 dict.insert(newbegin);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         path.pop_back();
//     }
};

int main(int argc, char** argv) {
    Solution s;
    string begin_word = "hit";
    string end_word = "cog";
    unordered_set<string> word_dict;
    word_dict.insert("hot");
    word_dict.insert("dot");
    word_dict.insert("dog");
    word_dict.insert("log");
    word_dict.insert("lot");
    auto ans = s.findLadders(begin_word, end_word, word_dict);
    for (auto v : ans) {
        for (auto str : v) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
