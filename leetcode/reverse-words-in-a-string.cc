// Question: https://leetcode.com/problems/reverse-words-in-a-string/

#include "headers.h"

class Solution {
public:
    void reverseWords(string &s) {
        trim(s);
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s.at(j) != ' ') {
                ++j;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        reverse(s.begin(), s.end());
    }

private:
    void trim(string& s) {
        int i = 0;
        while (i < s.size() && s.at(i) == ' ') {
            ++i;
        }
        int j = s.size() - 1;
        while (j >= 0 && s.at(j) == ' ') {
            --j;
        }
        if (i > j) {
            s = "";
        } else {
            int c = 0;
            int m = i;
            while (m <= j) {
                if (s.at(m) != ' ') {
                    s[c++] = s[m++];
                } else {
                    while (m <= j && s.at(m) == ' ') {
                        ++m;
                    }
                    s[c++] = ' ';
                }
            }
            s = s.substr(0, c);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        string str = " the sky is    blue  ";
        s.reverseWords(str);
        cout << str << "E" << endl;
    }
    {
        string str = "   ";
        s.reverseWords(str);
        cout << str << "E" << endl;
    }
    {
        string str = "test";
        s.reverseWords(str);
        cout << str << "E" << endl;
    }
    return 0;
}
