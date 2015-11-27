// Question: https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }

        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            int j = 0;
            while (i-j >= 0 && i+j <s.size() && s.at(i-j) == s.at(i+j)) {
                ++j;
            }
            if (2*j-1 > ans.size()) {
                ans = s.substr(i-j+1, 2*j-1);
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            int j = 0;
            while (i-j >= 0 && i+j+1 < s.size() && s.at(i-j) == s.at(i+j+1)) {
                ++j;
            }
            if (2*j > ans.size()) {
                ans = s.substr(i-j+1, 2*j);
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.longestPalindrome("a") << endl;
    cout << s.longestPalindrome("ab") << endl;
    cout << s.longestPalindrome("abc") << endl;
    cout << s.longestPalindrome("abbc") << endl;
    cout << s.longestPalindrome("abcdcbd") << endl;
}
