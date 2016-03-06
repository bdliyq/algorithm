// Question: https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int ssize = s.size();
        int psize = p.size();
        int sp = 0;
        int pp = 0;
        int sback = -1;
        int pback = -1;
        while (sp < ssize) {
            if (s[sp] == p[pp] || p[pp] == '?') {
                ++sp;
                ++pp;
            } else if (p[pp] == '*') {
                sback = sp+1;
                pback = pp++;
            } else if (sback != -1) {
                sp = sback;
                pp = pback;
            } else {
                return false;
            }
        }
        string subp = p.substr(pp);
        return count(subp.begin(), subp.end(), '*') == subp.size();
    }
};
