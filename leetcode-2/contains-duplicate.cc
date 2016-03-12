// Question: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if (s.count(n) > 0) {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};
