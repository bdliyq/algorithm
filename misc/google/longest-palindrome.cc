// Question: 求最大回文子串。

string solve(string s) {
    int len = s.size();
    int i = 0;
    string ans = "";
    while (i < len) {
        int j = 0;
        while (i+j < len && i-j >= 0 && s[i+j] == s[i-j]) { ++j; }
        if (ans.size() < 2*j-1) {
            ans = s.substr(i-j+1, 2*j-1);
        }

        j = 0;
        while (i+j+1 < len && i-j >= 0 && s[i+j+1] == s[i-j]) { ++j; }
        if (ans.size() < 2*j) {
            ans = s.substr(i-j+1, 2*j);
        }
        ++i;
    }
    return ans;
}
