// Question: 给定一个string，返回含有word的列表。

#include "headers.h"

vector<string> solve(string s) {
    vector<string> ans;
    int len = s.size();
    int i = 0;
    while (i < len && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')) {
        ++i;
    }

    int start = i;
    while (i < len) {
        while (i < len && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
            ++i;
        }
        ans.push_back(s.substr(start, i-start));

        while (i < len && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')) {
            ++i;
        }
        start = i;
    }

    return ans;
}

int main(int argc, char** argv) {
    auto v = solve("  I    have  a \"faux coat\" ");
    for (auto s : v) {
        cout << s << endl;
    }
}
