// Question: https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> m1, m2;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (m1.count(s[i]) == 0) {
                m1[s[i]] = t[i];
            } else {
                if (m1[s[i]] != t[i]) {
                    return false;
                }
            }

            if (m2.count(t[i]) == 0) {
                m2[t[i]] = s[i];
            } else {
                if (m2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
