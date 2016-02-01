// Question: https://leetcode.com/problems/integer-to-roman/

#include "headers.h"

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbol{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> value{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int i = 0;
        string ans("");
        while (num != 0) {
            if (num >= value[i]) {
                num -= value[i];
                ans += symbol[i];
            } else {
                i += 1;
            }
        }
        return ans;
    }
};
