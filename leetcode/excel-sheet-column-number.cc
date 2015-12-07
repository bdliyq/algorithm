// Question: https://leetcode.com/problems/excel-sheet-column-number/

#include "headers.h"

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (auto c : s) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.titleToNumber("A") << endl;
    cout << s.titleToNumber("B") << endl;
    cout << s.titleToNumber("Z") << endl;
    cout << s.titleToNumber("AA") << endl;
    cout << s.titleToNumber("AB") << endl;
    cout << s.titleToNumber("AAA") << endl;
}
