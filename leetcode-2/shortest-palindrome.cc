// Question: https://leetcode.com/problems/shortest-palindrome/

class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1, k = j;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                --k;
                i = 0;
                j = k;
            }
        }
        string sub = s.substr(k+1);
        reverse(sub.begin(), sub.end());
        return sub + s;
    }
};
