// Question: https://leetcode.com/problems/plus-one/

#include "headers.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return vector<int>{1};
        }

        reverse(digits.begin(), digits.end());

        int carry = 1;
        for (int i = 0; i < digits.size(); ++i) {
            int t = digits[i] + carry;
            digits[i] = t % 10;
            carry = t / 10;
        }
        if (carry != 0) {
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> digits{9,9,9};
    vector<int> ans = s.plusOne(digits);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
