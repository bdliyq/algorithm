// Question: https://leetcode.com/problems/word-pattern/

#include "headers.h"

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, string> m1;
        unordered_map<string, string> m2;
        vector<string> vs = split(str, ' ');
        if (pattern.size() != vs.size()) {
            return false;
        }

        int len = pattern.size();
        for (int i = 0; i < len; ++i) {
            string p = pattern.substr(i, 1);
            if (m1.count(p) == 0 && m2.count(vs.at(i)) == 0) {
                m1[p] = vs.at(i);
                m2[vs.at(i)] = p;
            } else if (!(m1.count(p) > 0 && m2.count(vs.at(i)) > 0 && m1[p] == vs.at(i) && m2[vs.at(i)] == p)) {
                return false;
            }
        }

        return true;
    }

private:
    vector<string> split(string s, char c) {
        vector<string> v;
        int begin = 0;
        int end = 0;
        while (end < s.size()) {
            if (s[end] == ' ') {
                v.push_back(s.substr(begin, end-begin));
                begin = end + 1;
            }
            ++end;
        }
        if (end - begin > 0) {
            v.push_back(s.substr(begin, end-begin));
        }
        return v;
    }

    void print_vec(vector<string>& v) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    return 0;
}
