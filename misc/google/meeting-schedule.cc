// Question: 给定一些会议的起始和结束时间，求总共需要多少会议室。

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

struct cmp {
    bool operator() (Interval& i1, Interval& i2) {
        return i1.start < i2.start;
    }
};

int solve(vector<Interval>& meetings) {
    if (meetings.empty()) {
        return 0;
    }

    sort(meetings.begin(), meetings.end(), cmp);
    priority_queue<int> pq;
    pq.push(meetings[0].end);
    for (int i = 1; i < meetings.size(); ++i) {
        if (meetings[i].start >= pq.front()) {
            pq.pop();
        }
        pq.push(meetings[i].end);
    }

    return pq.size();
}
