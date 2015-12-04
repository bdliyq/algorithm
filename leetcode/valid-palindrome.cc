// Question: https://leetcode.com/problems/valid-palindrome/

#include "headers.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !(isalpha(s[left]) || isdigit(s[left]))) {
                ++left;
            }
            while (left < right && !(isalpha(s[right]) || isdigit(s[right]))) {
                --right;
            }
            if (!(s[left] - s[right] == 0 || abs(s[left] - s[right]) == 32)) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isPalindrome(" A man, a plan, a canal: Panama  ") << endl;
    cout << s.isPalindrome("   ") << endl;
    cout << s.isPalindrome(" a  ") << endl;
    cout << s.isPalindrome(" aa  ") << endl;
}
