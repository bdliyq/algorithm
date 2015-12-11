// Question: https://leetcode.com/problems/minimum-window-substring/

#include "headers.h"

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) { ++m[c]; }

        int head = 0, begin = 0, end = 0, minlen = INT_MAX, cnt = t.size();
        while (end < s.size()) {
            if (m[s[end++]]-- > 0) { --cnt; }
            while (cnt == 0) {
                if (minlen > end-begin) {
                    head = begin;
                    minlen = end-begin;
                }
                if (m[s[begin++]]++ == 0) { ++cnt; }
            }
        }

        return (minlen == INT_MAX ? "" : s.substr(head, minlen));
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.minWindow("A", "A") << endl;
    return 0;
}
