// Question: 一个由()组成的字符串，判断是否是valid。

bool valid(const string& p) {
    int d = 0;
    for (char c : p) {
        if (c == '(') {
            ++d;
        } else {
            --d;
            if (d < 0) {
                return false;
            }
        }
    }
    return true;
}
