// Question: Combine intervals.

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

struct cmp {
    bool operator() (Interval& i1, Interval& i2) {
        return (i1.start < i2.start);
    }
};

vector<Interval> solve(vector<Interval> intervals) {
    vector<Interval> ans;
    if (intervals.empty()) {
        return ans;
    }

    sort(intervals.begin(), intervals.end());
    for (auto i : intervals) {
        if (ans.empty() || ans.back().end < i.start) {
            ans.push_back(i);
        } else {
            ans.back().end = max(ans.back().end, i.end);
        }
    }
    return ans;
}
