// Question: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto n : nums) {
            if (s.count(n) > 0) {
                int count = 1;
                s.erase(n);

                int t = n+1;
                while (s.count(t) > 0) {
                    s.erase(t);
                    ++t;
                    ++count;
                }
                t = n-1;
                while (s.count(t) > 0) {
                    s.erase(t);
                    --t;
                    ++count;
                }

                ans = max(ans, count);
            }
        }
        return ans;
    }
};
