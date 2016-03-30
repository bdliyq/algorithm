// Question: 给定一个矩阵包含0和1，求由1构成的正方形最大面积。

int maximal_square(vector<vector<int>> matrix) {
    if (matrix.empty() || matrix.at(0).empty()) {
        return 0;
    }
    int row = matrix.size();
    int col = matrix.at(0).size();
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
    int size = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == 1) {
                dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
                size = max(size, dp[i+1][j+1]);
            }
        }
    }

    return size * size;
}

// Question: 给定一个矩阵包含0和1，求由1构成的矩形最大面积。

int maximal_rectangle(vector<vector<int>> matrix) {
    if (matrix.empty() || matrix.at(0).empty()) {
        return 0;
    }
    int row = matrix.size();
    int col = matrix.at(0).size();
    vector<int> height(col, 0);
    int ans = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == 0) {
                height[j] = 0;
                continue;
            }
            ++height[j];
            int pre = height[j];
            for (int k = j; k >= 0; --k) {
                pre = min(pre, height[k]);
                ans = max(ans, (j-k+1) * pre);
            }
        }
    }
    return ans;
}
