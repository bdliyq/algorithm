// Question: https://leetcode.com/problems/4sum/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < nums.size(); ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int l = j+1;
                int r = nums.size()-1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        while (l < nums.size()-1 && nums[l] == nums[l+1]) {
                            ++l;
                        }
                        while (r > 0 && nums[r] == nums[r-1]) {
                            --r;
                        }
                        ++l;
                        --r;
                    } else if (sum < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    vector<int> nums{1,0,-1,0,2,-2,1,-1};
    Solution s;
    vector<vector<int>> ans = s.fourSum(nums, 0);
    for (auto i = ans.begin(); i != ans.end(); ++i) {
        for (auto j = i->begin(); j != i->end(); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}
