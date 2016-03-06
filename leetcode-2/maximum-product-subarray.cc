// Question: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int minprod = nums[0], maxprod = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            int newmin = min(n, min(minprod*n, maxprod*n));
            int newmax = max(n, max(minprod*n, maxprod*n));
            minprod = newmin;
            maxprod = newmax;
            ans = max(ans, maxprod);
        }
        return ans;
    }
};
