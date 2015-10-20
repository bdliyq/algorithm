#!/usr/bin/env python
# encoding: utf-8

# http://www.lintcode.com/en/problem/merge-intervals/

"""
Definition of Interval.
"""
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution:
    def find(self, intervals, num):
        low, high = 0, len(intervals) - 1
        while low <= high:
            mid = (low + high) / 2
            if intervals[mid].start <= num and num <= intervals[mid].end:
                return (mid, True)
            elif intervals[mid].start > num:
                high = mid - 1
            elif intervals[mid].end < num:
                low = mid + 1

        return low, False

    def insert(self, intervals, newInterval):
        results = []
        # write your code here
        istart, fstart = self.find(intervals, newInterval.start)
        iend, fend = self.find(intervals, newInterval.end)
        if fstart and fend:
            results.extend(intervals[:istart])
            results.append(Interval(intervals[istart].start, intervals[iend].end))
            results.extend(intervals[iend+1:])
        elif fstart and not fend:
            results.extend(intervals[:istart])
            results.append(Interval(intervals[istart].start, newInterval.end))
            results.extend(intervals[iend:])
        elif not fstart and fend:
            results.extend(intervals[:istart])
            results.append(Interval(newInterval.start, intervals[iend].end))
            results.extend(intervals[iend+1:])
        else:
            results.extend(intervals[:istart])
            results.append(newInterval)
            results.extend(intervals[iend:])

        return results

    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        # write your code here
        results = []
        for i in intervals:
            results = self.insert(results, i)
        return results

def print_results(results):
    array = []
    for r in results:
        array.append([r.start, r.end])
    print array

if __name__ == '__main__':
    s = Solution()
    print_results(s.merge([Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)]))
