// Question: 给定一个整数，求minlen，minlen定义为多少个完全平方数之和。
// 例如：14=1+4+9；minlen = 3

int solve(int n) {
    if (n <= 0) {
        return 0;
    }

    vector<int> dp(n+1, INT_MAX);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = i*i; j <= n; j *= j) {
            dp[j] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] == INT_MAX) {
            for (int j = 1; j*j <= i; ++j) {
                int diff = i - j*j;
                dp[i] = min(dp[i], dp[diff]+1);
            }
        }
    }

    return dp.back();

    // vector<int> dp(n+1, INT_MAX);
    // dp[1] = 1;
    // for (int i = 2; i <= n; ++i) {
    //     for (int j = i*i; j <= n; j *= j) {
    //         dp[j] = 1;
    //     }
    // }

    // for (int i = 1; i <= n; ++i) {
    //     if (dp[i] == INT_MAX) {
    //         for (int j = 1; j*j <= i; ++j) {
    //             int diff = i-j*j;
    //             dp[i] = min(dp[i], dp[diff]+1);
    //         }
    //     }
    // }

    // return dp.back();
}
