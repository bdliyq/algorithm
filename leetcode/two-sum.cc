// Question: https://leetcode.com/problems/two-sum/

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() <= 1) {
            return vector<int>();
        }

        map<int, int> m;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i]) > 0) {
                vector<int> ans;
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i+1);
                return ans;
            }
            m[nums[i]] = i+1;
        }

        return vector<int>();
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    Solution s;
    vector<int> ans = s.twoSum(nums, 9);
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans.at(i) << endl;
    }
}
