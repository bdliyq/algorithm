#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/insert-interval/

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

    """
    Insert a new interval into a sorted non-overlapping interval list.
    @param intevals: Sorted non-overlapping interval list
    @param newInterval: The new interval.
    @return: A new sorted non-overlapping interval list with the new interval.
    """
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

def print_results(results):
    array = []
    for r in results:
        array.append([r.start, r.end])
    print array

if __name__ == '__main__':
    s = Solution()
    print_results(s.insert([Interval(10,12), Interval(15,19)], Interval(13, 17)))
    print_results(s.insert([Interval(10,12), Interval(15,19)], Interval(3, 7)))
    print_results(s.insert([Interval(10,12), Interval(15,19)], Interval(3, 27)))
    print_results(s.insert([Interval(10,12), Interval(15,19)], Interval(11, 17)))
    print_results(s.insert([Interval(10,12), Interval(15,19)], Interval(111, 117)))
    print_results(s.insert([], Interval(111, 117)))
