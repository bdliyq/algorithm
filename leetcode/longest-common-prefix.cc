// Question: https://leetcode.com/problems/longest-common-prefix/

#include "headers.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.empty()) {
            return ans;
        }

        int i = 0;
        while (true) {
            string sub = "";
            int j = 0;
            while (j < strs.size()) {
                string s = strs.at(j);
                if (i >= s.size()) {
                    break;
                }
                if (sub.size() == 0) {
                    sub = s.substr(0, i+1);
                } else {
                    if (s.substr(0, i+1) != sub) {
                        break;
                    }
                }
                ++j;
            }
            if (j == strs.size()) {
                ans = sub;
            } else {
                break;
            }
            ++i;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    vector<string> strs{"abc", "abcd", "ab"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
