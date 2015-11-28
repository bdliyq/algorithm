// Question: https://leetcode.com/problems/palindrome-partitioning/

#include "headers.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        helper(s, path, ans);
        return ans;
    }

private:
    void helper(string s, vector<string>& path, vector<vector<string>>& ans) {
        if (s.empty()) {
            return;
        }

        if (is_palindrome(s)) {
            path.push_back(s);
            ans.push_back(path);
            path.pop_back();
        }

        for (int i = 0; i < s.size(); ++i) {
            string left = s.substr(0, i);
            if (is_palindrome(left)) {
                path.push_back(left);
                helper(s.substr(i), path, ans);
                path.pop_back();
            }
        }
    }

    bool is_palindrome(string s) {
        if (s.empty()) {
            return false;
        }
        string old = s;
        reverse(s.begin(), s.end());
        return old == s;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        vector<vector<string>> ans = s.partition("aab");
        for (auto v : ans) {
            for (auto a : v) {
                cout << a << " ";
            }
            cout << endl;
        }
    }
    {
        vector<vector<string>> ans = s.partition("abc");
        for (auto v : ans) {
            for (auto a : v) {
                cout << a << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
