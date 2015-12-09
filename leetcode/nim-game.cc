// Question: https://leetcode.com/problems/nim-game/

#include "headers.h"

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3) {
            return true;
        }

        // bool i = true;
        // bool j = true;
        // bool k = true;
        // for (int idx = 4; idx <= n; ++idx) {
        //     bool r = !i || !j || !k;
        //     i = j;
        //     j = k;
        //     k = r;
        // }

        // return k;

        return n % 4 != 0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    for (int i = 1; i < 100; ++i) {
        cout << i << " " << s.canWinNim(i) << endl;
    }
    cout << s.canWinNim(1348820612) << endl;
    return 0;
}
