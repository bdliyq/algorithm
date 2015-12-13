// Question: https://leetcode.com/problems/add-digits/

#include "headers.h"

class Solution {
public:
    int addDigits(int num) {
        if (num <= 9) {
            return num;
        }

        return 1 + ((num - 1) % 9);
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.addDigits(38) << endl;
    return 0;
}
