// Question: 将一个数据right rotate k。inplace，O(n)

void solve(vector<int>& nums, int k) {
    int len = nums.size();
    if (len == 0) {
        return;
    }

    k = k % len;
    reverse(nums.begin(), nums.begin() + len - k);
    reverse(nums.begin(), nums.end());
}
