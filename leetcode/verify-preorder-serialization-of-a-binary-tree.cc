// Question: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

#include "headers.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes = split(preorder, ',');
        int d = 0;
        for (int i = 0; i < (int)nodes.size() - 1; ++i) {
            string n = nodes.at(i);
            if (n == "#") {
                if (d == 0) {
                    return false;
                } else {
                    --d;
                }
            } else {
                ++d;
            }
        }
        return d != 0 ? false : nodes.back() == "#";
    }

private:
    vector<string> split(string s, char c) {
        vector<string> v;
        int begin = 0;
        int end = 0;
        while (end < s.size()) {
            if (s[end] == c) {
                v.push_back(s.substr(begin, end-begin));
                begin = end + 1;
            }
            ++end;
        }
        if (end - begin > 0) {
            v.push_back(s.substr(begin, end-begin));
        }
        return v;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("9,#,#,1") << endl;
    return 0;
}
