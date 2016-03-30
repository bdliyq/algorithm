// Question: Bigint相加。

vector<int> bigint_add(vector<int> a, vector<int> b) {
    int lena = a.size(), lenb = b.size();
    if (lena == 0) {
        return b;
    }
    if (lenb == 0) {
        return a;
    }

    vector<int> ans;
    int carry = 0;
    int i = lena-1;
    int j = lenb-1;
    while (i >= 0 && j >= 0) {
        int t = a[i] + b[j] + carry;
        carry = t / 10;
        ans.push_back(t % 10);
        --i;
        --j;
    }
    while (i >= 0) {
        int t = a[i] + carry;
        carry = t / 10;
        ans.push_back(t % 10);
        --i;
    }
    while (j >= 0) {
        int t = b[j] + carry;
        carry = t / 10;
        ans.push_back(t % 10);
        --j;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
