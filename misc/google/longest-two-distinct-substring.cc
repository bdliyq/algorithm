// Question: 找到只包含2个distinct ASCII character的最长substring。

string solve(string s) {
    unordered_map<char, int> m;
    int len = s.size();
    int i = 0;
    int j = 0;
    int max_len = 0;
    int start = 0;
    while (j < len) {
        m[s[j]]++;
        while (m.size() > 2) {
            while (i < j) {
                m[s[i]]--;
                if (m[s[i]] == 0) {
                    m.erase(s[i]);
                    ++i;
                    break;
                }
                ++i;
            }
        }

        if (m.size() == 2) {
            if (j-i+1 > max_len) {
                start = i;
                max_len = j-i+1;
            }
        }
        ++j;
    }

    return s.substr(start, max_len);
}
