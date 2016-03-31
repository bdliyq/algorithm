// Question: 给定2个sorted array，求交。

vector<int> solve(vector<int>& va, vector<int>& vb) {
    vector<int> ans;
    int i = 0, j = 0, lena = va.size(), lenb = vb.size();
    while (i < lena && j < lenb) {
        if (va[i] == vb[j]) {
            ans.push_back(va[i]);
            ++i;
            ++j;
        } else if (va[i] > vb[j]) {
            ++j;
        } else {
            ++i;
        }
    }
    return ans;
}
