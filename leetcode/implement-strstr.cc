// Question: https://leetcode.com/problems/implement-strstr/

#include "headers.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= (int)haystack.size()-(int)needle.size(); ++i) {
            int j = 0;
            for (; j < needle.size(); ++j) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.strStr("", "a") << endl;
    return 0;
}
