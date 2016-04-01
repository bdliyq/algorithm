// Question: 找丑数。

int solve(int n) {
    vector<int> ans;
    ans.push_back(1);
    int i = 0, j = 0, k = 0;
    int m = 0;
    while (m++ < n) {
        int a = ans.at(i) * 2;
        int b = ans.at(j) * 3;
        int c = ans.at(k) * 5;
        int f = min(min(a, b), c);
        if (f % 2 == 0) {
            ++i;
        }
        if (f % 3 == 0) {
            ++j;
        }
        if (f % 5 == 0) {
            ++k;
        }
        ans.push_back(f);
    }

    return ans.back();
}
