// Question: Paint houses in the cheapest way.

const int N = 30; // 房屋数
// A: 每个房屋用3中颜色paint的cost。
int solve(int A[3][N]) {
    int dp[3][N];
    dp[0][0] = A[0][0];
    dp[1][0] = A[1][0];
    dp[2][0] = A[2][0];

    for (int i = 1; i < N; ++i) {
        dp[0][i] = A[0][i] + min(A[1][i], A[2][i]);
        dp[1][i] = A[1][i] + min(A[0][i], A[2][i]);
        dp[2][i] = A[2][i] + min(A[0][i], A[1][i]);
    }

    return min(min(dp[0][N-1], dp[1][N-1]), dp[2][N-1]);
}
