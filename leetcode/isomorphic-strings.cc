// Question: https://leetcode.com/problems/isomorphic-strings/

#include "headers.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> chmap1, chmap2;
        for (int i = 0; i < s.size(); ++i) {
            if (chmap1.count(s[i]) == 0) {
                chmap1[s[i]] = t[i];
            } else {
                if (chmap1[s[i]] != t[i]) {
                    return false;
                }
            }

            if (chmap2.count(t[i]) == 0) {
                chmap2[t[i]] = s[i];
            } else {
                if (chmap2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isIsomorphic("ab", "ab") << endl;
}
