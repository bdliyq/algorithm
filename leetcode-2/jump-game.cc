// Question: https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        int max_jump = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            max_jump = max(max_jump, i+nums[i]);
            if (max_jump >= nums.size()) {
                return true;
            }
            if (max_jump <= i) {
                return false;
            }
        }
        return max_jump >= nums.size();
    }
};
