// Question: Next permutation.

void solve(vector<int> nums) {
    int len = nums.size();
    int i = len-2;
    while (i >= 0) {
        if (nums[i+1] > nums[i]) {
            int j = len-1;
            while (i < j) {
                if (nums[j] > nums[i]) {
                    break;
                }
                --j;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
        --i;
    }
    reverse(nums.begin(), nums.end());
}
