// Question: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size()-1;
        while (i < j) {
            while (i < j && !isdigit(s[i]) && !isalpha(s[i])) {++i;}
            while (i < j && !isdigit(s[j]) && !isalpha(s[j])) {--j;}
            if (i < j) {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
            }
            ++i;
            --j;
        }
        return true;
    }
};
