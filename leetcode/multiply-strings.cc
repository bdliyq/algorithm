// Question: https://leetcode.com/problems/multiply-strings/

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty()) {
            return num2;
        }
        if (num2.empty()) {
            return num1;
        }

        int sign = 1;
        if (num1.at(0) == '-' || num1.at(0) == '+') {
            if (num1.at(0) == '-') {
                sign *= -1;
            }
            num1 = num1.substr(1);
        }
        if (num2.at(0) == '-' || num1.at(0) == '+') {
            if (num2.at(0) == '-') {
                sign *= -1;
            }
            num2 = num2.substr(1);
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        vector<int> res;
        for (int i = 0; i < num1.size(); ++i) {
            int offset = i;
            for (int j = 0; j < num2.size(); ++j, ++offset) {
                int x = num1.at(i) - '0';
                int y = num2.at(j) - '0';
                add(res, carry, x*y, offset);
            }
            while (carry > 0) {
                int new_carry = 0;
                add(res, new_carry, carry, offset++);
                carry = new_carry;
            }
            // print_vec(res);
        }

        stringstream ss;
        bool flag = false;
        for (int i = res.size()-1; i >= 0; --i) {
            if (res.at(i) == 0) {
                if (flag) {
                    ss << res.at(i);
                }
            } else {
                ss << res.at(i);
                flag = true;
            }
        }
        if (ss.str().empty()) {
            return "0";
        }
        if (sign == -1 && ss.str().size() > 0 && ss.str() != "0") {
            return "-" + ss.str();
        }
        return ss.str();
    }

private:
    void add(vector<int>& res, int& carry, int incr, int offset) {
        if (offset >= res.size()) {
            int am = incr + carry;
            res.push_back(am % 10);
            carry = am / 10;
        } else {
            int am = res[offset] + incr + carry;
            res[offset] = am % 10;
            carry = am / 10;
        }
    }

    void print_vec(vector<int>& v) {
        for (int i = 0; i < v.size(); ++i) {
            cout << v.at(i) << " ";
        }
        cout << endl;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.multiply("123", "45") << endl;
    cout << s.multiply("", "45") << endl;
    cout << s.multiply("-1", "45") << endl;
    cout << s.multiply("+123", "45") << endl;
    cout << s.multiply("+123", "-45") << endl;
    cout << s.multiply("0", "-45") << endl;
}
