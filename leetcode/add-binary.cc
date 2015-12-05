// Question: https://leetcode.com/problems/add-binary/

#include "headers.h"

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) {
            return addBinary(b, a);
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        stringstream ss;
        int carry = 0;
        for (int i = 0; i < a.size(); ++i) {
            int x = a[i] - '0';
            int y = b[i] - '0';
            int r = x+y+carry;
            int s = r % 2;
            carry = r / 2;
            ss << s;
        }
        for (int i = a.size(); i < b.size(); ++i) {
            int x = b[i] - '0';
            int r = x+carry;
            int s = r % 2;
            carry = r / 2;
            ss << s;
        }
        if (carry) {
            ss << carry;
        }

        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;
}
