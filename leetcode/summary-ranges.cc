// Question: https://leetcode.com/problems/summary-ranges/

#include "headers.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }

        int start = nums[0];
        int end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != end + 1) {
                ans.push_back(make_ans(start, end));
                start = nums[i];
                end = nums[i];
            } else {
                end = nums[i];
            }
        }
        ans.push_back(make_ans(start, end));

        return ans;
    }

private:
    string make_ans(int start, int end) {
        stringstream ss;
        if (start == end) {
            ss << start;
        } else {
            ss << start << "->" << end;
        }
        return ss.str();
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{-1};
    vector<string> ans = s.summaryRanges(nums);
    for (auto s : ans) {
        cout << s << endl;
    }
    return 0;
}
