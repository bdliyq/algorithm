// Question: https://leetcode.com/problems/regular-expression-matching/

#include "headers.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s.c_str(), p.c_str());
    }

private:
    bool helper(const char* s, const char* p) {
        if (*p == 0) {
            return *s == 0;
        }

        if (*(p+1) != '*') {
            return (*s == *p || (*s != 0 && *p == '.')) && helper(++s, ++p);
        }

        while (*s == *p || (*s != 0 && *p == '.')) {
            if (helper(s, p+2)) {
                return true;
            }
            ++s;
        }

        return helper(s, p+2);
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("aa", ".*") << endl;
    cout << s.isMatch("ab", ".*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
}
