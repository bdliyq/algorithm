// Question: https://leetcode.com/problems/integer-to-english-words/

#include "headers.h"

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        vector<string> hundreds{"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};
        vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> ones{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> units{"", "Thousand", "Million", "Billion"};

        string ans("");
        int u = 0;
        while (num != 0) {
            int left = num % 1000;

            int one = left % 10;
            left /= 10;
            int ten = left % 10;
            left /= 10;
            int hun = left % 10;

            string part("");
            part += hundreds[hun];
            if (ten != 1) {
                if (!part.empty() && ten != 0) {
                    part += " " + tens[ten];
                } else {
                    part += tens[ten];
                }
                if (!part.empty() && one != 0) {
                    part += " " + ones[one];
                } else {
                    part += ones[one];
                }
            } else {
                if (!part.empty()) {
                    part += " " + teens[one];
                } else {
                    part += teens[one];
                }
            }

            if (!part.empty()) {
                if (!part.empty() && u != 0) {
                    part += " " + units[u];
                } else {
                    part += units[u];
                }
            }

            if (!part.empty()) {
                if (ans.empty()) {
                    ans += part;
                } else {
                    ans = part + " " + ans;
                }
            }

            num = num / 1000;
            ++u;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numberToWords(1234567) << endl;
    cout << s.numberToWords(12) << endl;
    cout << s.numberToWords(0) << endl;
    cout << s.numberToWords(1000010) << endl;
    return 0;
}
