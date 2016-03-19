// Question: https://leetcode.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct cmp {
    bool operator() (const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        vector<Interval> ans;
        for (auto& interval : intervals) {
            if (ans.empty() || ans.back().end < interval.start) {
                ans.push_back(interval);
            } else {
                ans.back().end = max(ans.back().end, interval.end);
            }
        }
        return ans;
    }
};
