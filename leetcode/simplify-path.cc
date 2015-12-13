// Question: https://leetcode.com/problems/simplify-path/

#include "headers.h"

void print_vec(vector<string>& v) {
    cout << v.size() << " ";
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;
}

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vs = split(path, '/');
        stack<string> ss;
        for (string s : vs) {
            if (s.empty() || s == ".") {
                continue;
            }
            if (s == "..") {
                if (!ss.empty()) {
                    ss.pop();
                }
            } else {
                ss.push(s);
            }
        }
        string ans = "";
        while (!ss.empty()) {
            if (ans.empty()) {
                ans = ss.top() + ans;
            } else {
                ans = ss.top() + "/" + ans;
            }
            ss.pop();
        }
        return "/" + ans;
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
    cout << s.simplifyPath("/a/./b/../../c/d") << endl;
    cout << s.simplifyPath("/home/") << endl;
}
