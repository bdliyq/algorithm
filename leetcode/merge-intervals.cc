// Question: https://leetcode.com/problems/merge-intervals/

#include "headers.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Cmp {
    bool operator() (const Interval& i1, const Interval& i2) {
        if (i1.start == i2.start) {
            return i1.start < i2.start;
        }
        return i1.start < i2.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Cmp());

        vector<Interval> ans;
        int i = 0;
        while (i < intervals.size()) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            int j = i+1;
            while (j < intervals.size() && end >= intervals[j].start) {
                end = max(end, intervals[j].end);
                ++j;
            }
            ans.push_back(Interval(start, end));
            i = j;
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<Interval> intervals{Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)};
    auto ans = s.merge(intervals);
    for (auto i : ans) {
        cout << i.start << "," << i.end << " ";
    }
    cout << endl;
    return 0;
}
