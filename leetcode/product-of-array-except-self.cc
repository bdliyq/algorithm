// Question: https://leetcode.com/problems/product-of-array-except-self/

#include "headers.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int t = nums.back();
        for (int i = nums.size() - 2; i >= 0; --i) {
            ans[i] *= t;
            t *= nums[i];
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3,4};
    vector<int> ans = s.productExceptSelf(nums);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
