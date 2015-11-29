// Question: https://leetcode.com/problems/contains-duplicate-ii/

#include "headers.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i]) > 0) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,1,1,1};
    cout << s.containsNearbyDuplicate(nums, 3) << endl;
}
