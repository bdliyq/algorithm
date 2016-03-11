// Question: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX, c1 = 0, c2 = 0;
        for (auto n : nums) {
            if (c1 != 0 && n == n1) {
                ++c1;
            } else if (c2 != 0 && n == n2) {
                ++c2;
            } else if (c1 != 0 && c2 != 0) {
                --c1;
                --c2;
            } else if (c1 == 0) {
                c1 = 1;
                n1 = n;
            } else if (c2 == 0) {
                c2 = 1;
                n2 = n;
            }
        }
        vector<int> ans;
        if (count(nums.begin(), nums.end(), n1) > nums.size()/3) {
            ans.push_back(n1);
        }
        if (n2 != n1) {
            if (count(nums.begin(), nums.end(), n2) > nums.size()/3) {
                ans.push_back(n2);
            }
        }
        return ans;
    }
};
