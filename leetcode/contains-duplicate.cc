// Question: https://leetcode.com/problems/contains-duplicate/

#include "headers.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> exist;
        for (auto n : nums) {
            if (exist.count(n) > 0) {
                return true;
            }
            exist.insert(n);
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3,5,4};
    cout << s.containsDuplicate(nums) << endl;
}
