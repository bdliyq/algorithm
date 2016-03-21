// Question: https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }
        stringstream ss;
        while (n > 0) {
            char c = 'A' + (n-1) % 26;
            ss << c;
            n = (n-1) / 26;
        }
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
