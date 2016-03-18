// Question:
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//
// For example, Given [[0, 30],[5, 10],[15, 20]], return false.

struct cmp {
    bool operator () (const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval> intervals) {
        sort(intervals.begin(), intervals.end());
        int end = INT_MIN;
        for (auto& interval : intervals) {
            if (interval.start < end) {
                return false;
            }
            end = max(end, interval.end);
        }
        return true;
    }
}
