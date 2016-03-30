// Question: Fibonacci.

int solve(int n) {
    if (n <= 2) {
        return n-1;
    }

    int i = 0, j = 1;
    for (int k = 2; k < n; ++k) {
        int r = i + j;
        i = j;
        j = r;
    }
    return j;
}

int solve(int n) {
    if (n <= 2) {
        return n-1;
    }
    return solve(n-1) + solve(n-2);
}
