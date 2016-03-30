// Question: 给定字符串s、t，判断s里是否存在子字符串是t的anagram。

bool is_sub_anagram(string s, string t) {
    int lens = s.size();
    int lent = t.size();
    if (lent > lens) {
        return false;
    }

    sort(t.begin(), t.end());
    int i = 0;
    while (i <= lens - lent) {
        auto sub = s.substr(i, lent);
        sort(sub.begin(), sub.end());
        if (sub == t) {
            return true;
        }
    }

    return false;
}
