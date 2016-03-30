// Question: 螺旋打印matrix。

vector<int> solve(vector<vector<int>> matrix) {
    vector<int> ans;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return ans;
    }

    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0, right = col-1, top = 0, down = row-1;
    while (left <= right && top <= down) {
        for (int i = left; i <= right; ++i) {
            ans.push_back(matrix[top][i]);
        }
        ++top;
        for (int i = top; i <= down; ++i) {
            ans.push_back(matrix[i][right]);
        }
        --right;
        if (left <= right) {
            for (int i = right; i >= left; --i) {
                ans.push_back(matrix[down][i]);
            }
            --down;
        }
        if (top <= down) {
            for (int i = down; i >= top; --i) {
                ans.push_back(matrix[i][left];
            }
            ++left;
        }
    }
}
