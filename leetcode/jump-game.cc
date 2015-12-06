// Question: https://leetcode.com/problems/jump-game/

#include "headers.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_dist = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > max_dist || max_dist >= nums.size()-1) {
                break;
            }
            max_dist = max(max_dist, i + nums[i]);
        }
        return max_dist >= nums.size()-1;
    }
};
