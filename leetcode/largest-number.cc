// Question: https://leetcode.com/problems/largest-number/

#include "headers.h"

struct cmp {
    bool operator() (const string& s1, const string& s2) {
        return s1+s2 > s2+s1;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }

        vector<string> strs;
        for (auto n : nums) {
            stringstream ss;
            ss << n;
            strs.push_back(ss.str());
        }

        sort(strs.begin(), strs.end(), cmp());

        string ans;
        for (auto s : strs) {
            ans += s;
        }

        if (count(ans.begin(), ans.end(), '0') == ans.size()) {
            ans = '0';
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{0, 0};
    cout << s.largestNumber(nums) << endl;
    return 0;
}
