// Question: https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        if (num == 1) {
            return true;
        }

        while (num > 1) {
            bool f = false;
            if (num % 2 == 0) {
                num /= 2;
                f = true;
            }
            if (num % 3 == 0) {
                num /= 3;
                f = true;
            }
            if (num % 5 == 0) {
                num /= 5;
                f = true;
            }
            if (!f) {
                return false;
            }
        }
        return true;
    }
};
