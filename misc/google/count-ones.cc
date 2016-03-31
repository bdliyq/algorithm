// Question: 找出一个int值的二进制表示里有多少个1.

int solve(int n) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
        if ((n >> i) & 1) {
            ++ans;
        }
    }
    return ans;
}
