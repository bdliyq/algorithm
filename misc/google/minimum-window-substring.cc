// Question: leetcode, minimum window substring.

string min_win_substr(string s, string t) {
    vector<int> dict(128, 0);
    for (char c : t) {
        dict[c]++;
    }

    int i = 0, j = 0, start = 0, min_len = INT_MAX, cnt = t.size();
    while (j < s.size()) {
        if (dict[s[j++]]-- > 0) { --cnt; }
        while (cnt == 0) {
            if (min_len > j-i) {
                start = i;
                min_len = j-i;
            }
            if (dict[s[i++]]++ == 0) { ++cnt; }
        }
    }

    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}
