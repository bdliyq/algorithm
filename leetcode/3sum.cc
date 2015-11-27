// Question: https://leetcode.com/problems/3sum/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    int arr[] = {nums[i], nums[l], nums[r]};
                    ans.push_back(vector<int>(arr, arr+3));
                    while (l < nums.size() - 1 && nums[l] == nums[l+1]) {
                        ++l;
                    }
                    while (r > 0 && nums[r] == nums[r-1]) {
                        --r;
                    }
                    ++l;
                    --r;
                } else if (sum > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<vector<int> > ans = s.threeSum(nums);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans.at(i).size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
