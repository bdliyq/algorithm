// Question: Longest consecutive sequence.

int solve(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;
    for (int n : nums) {
        int cnt = 1;
        int k = n;
        while (s.count(k-1) > 0) {
            s.erase(k-1);
            --k;
            ++cnt;
        }
        k = n;
        while (s.count(k+1) > 0) {
            s.erase(k+1);
            ++k;
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    return ans;
}
