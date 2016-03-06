// Question: https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        int l = nums[0];
        int m = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            int a = nums[i];
            if (a <= l) {
                l = a;
            } else if (a < m) {
                m = a;
            } else if (a > m) {
                return true;
            }
        }
        return false;
    }
};
