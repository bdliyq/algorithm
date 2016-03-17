// Question: https://leetcode.com/problems/valid-number/

#include "headers.h"

class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();

        int start = 0;
        while (start < len && s[start] == ' ') {
            ++start;
        }
        if (start < len && (s[start] == '-' || s[start] == '+')) {
            ++start;
        }
        int end = start;
        while (end < len && s[end] >= '0' && s[end] <= '9') {
            ++end;
        }
        int len1 = end - start;

        start = end;
        if (start < len && s[start] == '.') {
            ++start;
        }
        end = start;
        while (end < len && s[end] >= '0' && s[end] <= '9') {
            ++end;
        }
        int len2 = end - start;

        if (len1 + len2 == 0) {
            return false;
        }

        start = end;
        if (start < len && (s[start] == 'e' || s[start] == 'E')) {
            ++start;
            if (start < len && (s[start] == '-' || s[start] == '+')) {
                ++start;
            }
            end = start;
            while (end < len && s[end] >= '0' && s[end] <= '9') {
                ++end;
            }
            if (end - start == 0) {
                return false;
            }
        }

        start = end;
        while (start < len && s[start] == ' ') {
            ++start;
        }
        return start == len;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isNumber(".20") << endl;
}
