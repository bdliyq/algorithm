// Question: https://leetcode.com/problems/shortest-palindrome/

#include "headers.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0, j = (int)s.size()-1, k = j;
        const char* data = s.data();
        while (i < j) {
            if (data[i] == data[j]) {
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

int main(int argc, char** argv) {
    Solution s;
    cout << s.shortestPalindrome("aacecaaa") << endl;
    cout << s.shortestPalindrome("abcd") << endl;
}
