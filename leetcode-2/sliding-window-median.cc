// Question: http://www.lintcode.com/en/problem/sliding-window-median/

#include <set>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        if (nums.empty() || nums.size() < k) {
            return ans;
        }

        multiset<int> left, right;
        for (int i = 0; i < k; ++i) {
            left.insert(nums[i]);
        }
        adjust(left, right, k);

        ans.push_back(*left.rbegin());
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i-k] > ans.back()) {
                right.erase(right.find(nums[i-k]));
            } else {
                left.erase(left.find(nums[i-k]));
            }

            if (!left.empty() && nums[i] < *left.rbegin()) {
                left.insert(nums[i]);
            } else {
                right.insert(nums[i]);
            }

            adjust(left, right, k);

            ans.push_back(*left.rbegin());
        }

        return ans;
    }

private:
    void adjust(multiset<int>& left, multiset<int>& right, int k) {
        while (left.size() < (k+1)/2) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        while (left.size() > (k+1)/2) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(5);
    vector<int> ans = s.medianSlidingWindow(vec, 3);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << endl;
    }
}
