// Question: https://leetcode.com/problems/ugly-number/

#include "headers.h"

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }

        while (num != 1) {
            bool flag = false;
            if (num % 5 == 0) {
                num /= 5;
                flag = true;
            }
            if (num % 3 == 0) {
                num /= 3;
                flag = true;
            }
            if (num % 2 == 0) {
                num /= 2;
                flag = true;
            }
            if (!flag) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isUgly(6) << endl;
    cout << s.isUgly(14) << endl;
    return 0;
}
