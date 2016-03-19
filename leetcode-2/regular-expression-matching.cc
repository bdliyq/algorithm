// Question: http://www.lintcode.com/en/problem/regular-expression-matching/

#include <iostream>

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (*p == 0) {
            return *s == 0;
        }

        if (*(p+1) != '*') {
            return ((*s == *p) || (*s != 0 && *p == '.')) && isMatch(s+1, p+1);
        }

        while ((*s == *p) || (*s != 0 && *p == '.')) {
            if (isMatch(s, p+2)) {
                return true;
            }
            s++;
        }

        return isMatch(s, p+2);
    }

};

int main(int argc, char** argv) {
    Solution s;
    bool ret = s.isMatch("ba", "b*");
    std::cout << (ret ? "true" : "false") << std::endl;
    return 0;
}
