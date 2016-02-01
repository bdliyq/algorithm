// Question: https://leetcode.com/problems/fraction-to-recurring-decimal/

#include "headers.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ans;
        bool neg = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0);
        long n = abs((long)numerator);
        long d = abs((long)denominator);
        long q = n / d;
        n %= d;
        ans << q;
        if (n != 0) {
            ans << ".";
        }

        unordered_map<int, int> m;
        int idx = ans.str().size();
        while (n != 0) {
            n *= 10;
            q = n / d;
            if (m.count(n) == 0) {
                ans << q;
                m[n] = idx;
                ++idx;
            } else {
                string s = ans.str();
                int pos = m[n];
                s.insert(pos, "(");
                s.append(")");
                if (neg) {
                    s = "-" + s;
                }
                return s;
            }
            n %= d;
        }

        string s = ans.str();
        if (neg) {
            s = "-" + s;
        }
        return s;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.fractionToDecimal(1, 2) << endl;
    cout << s.fractionToDecimal(2, 1) << endl;
    cout << s.fractionToDecimal(2, 3) << endl;
    return 0;
}
