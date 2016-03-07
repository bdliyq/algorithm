// Question: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i]) > 0) {
                return vector<int>{i, m[target-nums[i]]};
            }
            m[nums[i]] = i;
        }
    }
};
