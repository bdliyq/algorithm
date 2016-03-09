// Question: https://leetcode.com/problems/generate-parentheses/

#include "headers.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n, n);
        return ans;
    }

    void helper(vector<string>& ans, string path, int left, int right) {
        if (left == 0 && right == 0) {
            ans.push_back(path);
        }

        if (left <= right) {
            if (left >= 1) {
                helper(ans, path+"(", left-1, right);
            }
            if (right >= 1) {
                helper(ans, path+")", left, right-1);
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    auto ans = s.generateParenthesis(3);
    for (auto s : ans) {
        cout << s << endl;
    }
}
