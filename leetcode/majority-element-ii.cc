// Question: https://leetcode.com/problems/majority-element-ii/

#include "headers.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;
        for (int i : nums) {
            if (count1 != 0 && i == c1) {
                ++count1;
            } else if (count2 != 0 && i == c2) {
                ++count2;
            } else if (count1 != 0 && count2 != 0) {
                --count1;
                --count2;
            } else if (count1 == 0) {
                c1 = i;
                count1 = 1;
            } else if (count2 == 0) {
                c2 = i;
                count2 = 1;
            }
        }
        vector<int> ans;
        if (count(nums.begin(), nums.end(), c1) > nums.size() / 3) {
            ans.push_back(c1);
        }
        if (c2 != c1) {
            if (count(nums.begin(), nums.end(), c2) > nums.size() / 3) {
                ans.push_back(c2);
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1, 2, 1, 2, 1, 3, 2};
    vector<int> ans = s.majorityElement(nums);
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
