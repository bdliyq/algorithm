// Question: http://www.lintcode.com/en/problem/data-stream-median/

#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> ans;
        if (nums.empty()) {
            return ans;
        }

        multiset<int> left, right;
        for (int i = 0; i < nums.size(); ++i) {
            if (!left.empty() && nums[i] < *left.rbegin()) {
                left.insert(nums[i]);
            } else {
                right.insert(nums[i]);
            }
            adjust(left, right, i+1);
            ans.push_back(*left.rbegin());
        }

        return ans;
    }
private:
    void adjust(multiset<int>& left, multiset<int>& right, int k) {
        while (left.size() > (k+1)/2) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
        while (left.size() < (k+1)/2) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vector<int> ans = s.medianII(vec);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << endl;
    }
}
