// Question: https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int n = k % len;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + n);
        reverse(nums.begin() + n, nums.end());
    }
};
