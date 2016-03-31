// Question: Find first missing positive integer.

int solve(vector<int> nums) {
    if (nums.empty()) {
        return 1;
    }

    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        if (i+1 == nums[i]) {
            continue;
        }

        while (nums[i] > 0 && nums[i] <= len && i+1 != nums[i] && nums[i] != nums[nums[i]-1]) {
            int t = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = t;
        }
    }

    for (int i = 0; i < len; ++i) {
        if (nums[i] != i+1) {
            return i+1;
        }
    }
    return len+1;
}
