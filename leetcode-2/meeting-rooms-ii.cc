// Question:
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
// For example, Given [[0, 30],[5, 10],[15, 20]], return 2

struct cmp {
    bool operator () (const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());

        priority_queue<int> pq;
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= pq.front()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
}
