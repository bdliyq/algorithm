// Question: https://leetcode.com/problems/majority-element/

#include "headers.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int ans = nums[0];
        int cnt = 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == ans) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    ans = nums[i];
                    cnt = 1;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3,4,1,1,2,1,1,1,2,1,1,1};
    cout << s.majorityElement(nums) << endl;
    return 0;
}
