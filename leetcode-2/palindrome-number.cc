// Question: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x <= 9) {
            return true;
        }

        int y = 0;
        while (y < x) {
            y = y * 10 + x % 10;
            if (y == 0) {
                return false;
            }
            if (y == x || y == x/10) {
                return true;
            }
            x /= 10;
        }

        return false;
    }
};
