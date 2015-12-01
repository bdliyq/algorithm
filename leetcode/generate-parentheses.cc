// Question: https://leetcode.com/problems/generate-parentheses/

#include "headers.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, n, "", ans);
        return ans;
    }

private:
    void helper(int left, int right, string path, vector<string>& ans) {
        if (left == 0 && right == 0) {
            ans.push_back(path);
        } else if (left < 0 || right < 0 || left > right) {
            return;
        } else {
            helper(left-1, right, path+"(", ans);
            helper(left, right-1, path+")", ans);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (auto v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
