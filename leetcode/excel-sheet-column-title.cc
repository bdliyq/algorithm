// Question: https://leetcode.com/problems/excel-sheet-column-title/

#include "headers.h"

class Solution {
public:
    string convertToTitle(int n) {
        stringstream ss;
        while (n > 0) {
            int x = (n-1) % 26;
            char c = x + 'A';
            ss << c;
            n = (n-1) / 26;
        }
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(2) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(27) << endl;
    cout << s.convertToTitle(28) << endl;
    cout << s.convertToTitle(703) << endl;
}
