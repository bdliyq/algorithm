// Question: https://leetcode.com/problems/happy-number/

#include "headers.h"

class Solution {
public:
    bool isHappy(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        unordered_set<int> s;
        while (n != 1) {
            if (s.count(n) > 0) {
                break;
            }
            s.insert(n);

            int t = n;
            int new_n = 0;
            while (t) {
                int x = t % 10;
                t = t / 10;
                new_n += pow(x, 2);
            }
            n = new_n;
        }

        return n == 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isHappy(19) << endl;
    return 0;
}
