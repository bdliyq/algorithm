// Question: https://leetcode.com/problems/count-and-say/

#include "headers.h"

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            string t = "";
            char cha = ans[0];
            int cnt = 1;
            for (int j = 1; j < ans.size(); ++j) {
                if (cha == ans[j]) {
                    ++cnt;
                } else {
                    stringstream ss;
                    ss << cnt << cha;
                    cha = ans[j];
                    cnt = 1;
                    t += ss.str();
                }
            }

            stringstream ss;
            ss << cnt << cha;
            t += ss.str();

            ans = t;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.countAndSay(6) << endl;
}
