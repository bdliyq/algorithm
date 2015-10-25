#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/interval-sum/

"""
Definition of Interval.
"""
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution:
    def lowbit(self, i):
        return i & -i

    def sum(self, C, i):
        sum = 0
        while i > 0:
            sum += C[i]
            i -= self.lowbit(i)
        return sum

    def add(self, C, i, v):
        if i == 0:
            return
        while i < len(C):
            C[i] += v
            i += self.lowbit(i)

    """
    @param A, queries: Given an integer array and an Interval list
                       The ith query is [queries[i-1].start, queries[i-1].end]
    @return: The result list
    """
    def intervalSum(self, A, queries):
        # write your code here
        C = [0 for i in xrange(len(A)+1)]
        for i in xrange(len(A)):
            self.add(C, i+1, A[i])

        ans = []
        for q in queries:
            ans.append(self.sum(C, q.end+1) - self.sum(C, q.start))
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.intervalSum([1,2,7,8,5], [Interval(0,4), Interval(1,2), Interval(2,4)])
