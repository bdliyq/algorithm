// Question: https://leetcode.com/problems/length-of-last-word/

#include "headers.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size() - 1;
        while (j >= 0 && s[j] == ' ') {
            --j;
        }
        int i = j;
        while (j >= 0 && s[j] != ' ') {
            --j;
        }
        return i-j;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.lengthOfLastWord(" test abc def word    ") << endl;
    cout << s.lengthOfLastWord("    ") << endl;
    cout << s.lengthOfLastWord("") << endl;
}
