// Question: 判断给定数是否是2的幂。

bool solve(int n) {
    return !(n & -n);
}
