// Question: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) { m[c]++; }

        int i = 0, j = 0, start = 0, min_len = INT_MAX, cnt = t.size();
        while (j < s.size()) {
            if (m[s[j++]]-- > 0) { --cnt; }
            while (cnt == 0) {
                if (min_len > j-i) {
                    start = i;
                    min_len = j-i;
                }
                if (m[s[i++]]++ == 0) { ++cnt; }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
