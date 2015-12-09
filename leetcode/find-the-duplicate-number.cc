// Question: https://leetcode.com/problems/find-the-duplicate-number/

#include "headers.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int ans = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                while (true) {
                    slow = nums[slow];
                    ans = nums[ans];
                    if (slow == ans) {
                        return ans;
                    }
                }
            }
        }
    }
};
