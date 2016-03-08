// Question: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        helper(s, 0, path, ans);
        return ans;
    }

    void helper(string& s, int start, vector<string>& path, vector<vector<string>>& ans) {
        if (start >= s.size()) {
            ans.push_back(path);
        } else {
            for (int i = start; i < s.size(); ++i) {
                string sub = s.substr(start, i-start+1);
                if (is_palindrome(sub)) {
                    path.push_back(sub);
                    helper(s, i+1, path, ans);
                    path.pop_back();
                }
            }
        }
    }

    bool is_palindrome(string& s) {
        int len = s.size();
        for (int i = 0; i <= len/2; ++i) {
            if (s[i] != s[len-i-1]) {
                return false;
            }
        }
        return true;
    }
};
