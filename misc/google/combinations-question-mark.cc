// Question: 给定一个string，只包含｛0，1，？｝，其中？可以标示0或者1.求所有可能的组合。

#include "headers.h"

void bfs(string s, int start, string path, vector<string>& ans) {
    if (start >= s.size()) {
        ans.push_back(path);
        return;
    }

    if (s[start] == '?') {
        bfs(s, start+1, path+"0", ans);
        bfs(s, start+1, path+"1", ans);
    } else {
        bfs(s, start+1, path+s.substr(start, 1), ans);
    }
}

vector<string> solve(string s) {
    vector<string> ans;
    string path("");
    bfs(s, 0, path, ans);
    return ans;
}

int main(int argc, char** argv) {
    auto v = solve("10??1");
    for (auto s : v) {
        cout << s << endl;
    }
}
