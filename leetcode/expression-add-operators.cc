// Question: https://leetcode.com/problems/expression-add-operators/

#include "headers.h"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        for (int i = 1; i <= num.size(); ++i) {
            if (i == 1 || (i > 1 && num[0] != '0')) {
                string left = num.substr(0, i);
                string right = num.substr(i);
                helper(right, left, atol(left.c_str()), atol(left.c_str()), target, ans);
            }
        }
        return ans;
    }

private:
    void helper(string num, string t, long cur, long last, long target, vector<string>& ans) {
        if (num.empty()) {
            if (cur == target) {
                ans.push_back(t);
            }
        } else {
            for (int i = 1; i <= num.size(); ++i) {
                if (i == 1 || (i > 1 && num[0] != '0')) {
                    string left = num.substr(0, i);
                    string right = num.substr(i);
                    int v = atol(left.c_str());
                    helper(right, t + "+" + left, cur+v, v, target, ans);
                    helper(right, t + "-" + left, cur-v, -v, target, ans);
                    helper(right, t + "*" + left, cur-last+last*v, last*v, target, ans);
                }
            }
        }
    }
};

void print_vec(vector<string>& v) {
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    Solution s;
    {
        auto ans = s.addOperators("2147483648", -2147483648);
        print_vec(ans);
    }
    {
        auto ans = s.addOperators("2147483647", 2147483647);
        print_vec(ans);
    }
    // {
    //     auto ans = s.addOperators("23", 6);
    //     print_vec(ans);
    // }
    // {
    //     auto ans = s.addOperators("105", 5);
    //     print_vec(ans);
    // }
    // {
    //     auto ans = s.addOperators("123", 6);
    //     print_vec(ans);
    // }
    // {
    //     auto ans = s.addOperators("232", 8);
    //     print_vec(ans);
    // }
    // {
    //     auto ans = s.addOperators("00", 0);
    //     print_vec(ans);
    // }
}
