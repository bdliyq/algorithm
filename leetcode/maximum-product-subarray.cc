// Question: https://leetcode.com/problems/maximum-product-subarray/

#include "headers.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int min_ans = nums.at(0);
        int max_ans = nums.at(0);
        int ans = nums.at(0);
        for (int i = 1; i < nums.size(); ++i) {
            int tmp = min_ans;
            min_ans = min(nums.at(i), min(min_ans * nums.at(i), max_ans * nums.at(i)));
            max_ans = max(nums.at(i), max(tmp * nums.at(i), max_ans * nums.at(i)));
            ans = max(ans, max_ans);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{2,3,-2,4};
    cout << s.maxProduct(nums) << endl;
}
