// Question: 一维数组，求最大的subarray包含连续的1.

int max_subarray(vector<int> nums) {
    int ans = 0;
    int t = 0;
    for (int n : nums) {
        if (n == 1) {
            ++t;
        } else {
            ans = max(ans, t);
            t = 0;
        }
    }
    return ans;
}
