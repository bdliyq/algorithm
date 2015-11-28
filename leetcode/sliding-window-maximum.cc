// Question: https://leetcode.com/problems/sliding-window-maximum/

#include <queue>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k || nums.empty()) {
            return vector<int>();
        }

        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans;
        for (int i = k; i < nums.size(); ++i) {
            ans.push_back(nums[q.front()]);
            while (!q.empty() && q.front() <= i-k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,3,1,2,0,5};
    int k = 3;
    vector<int> ans = s.maxSlidingWindow(nums, k);
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
