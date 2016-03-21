// Question: https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        string ans = "1";
        for (int i = 1; i < n; ++i) {
            char c = ans[0];
            int cnt = 1;
            string t = "";
            for (int j = 1; j < ans.size(); ++j) {
                if (c == ans[j]) {
                    ++cnt;
                } else {
                    stringstream ss;
                    ss << cnt << c;
                    t += ss.str();
                    cnt = 1;
                    c = ans[j];
                }
            }
            stringstream ss;
            ss << cnt << c;
            t += ss.str();
            ans = t;
        }
        return ans;
    }
};
