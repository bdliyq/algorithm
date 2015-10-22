#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/first-bad-version/

class VersionControl:
    @classmethod
    def isBadVersion(cls, id)
        # Run unit tests to check whether verison `id` is a bad version
        # return true if unit tests passed else false.
# You can use VersionControl.isBadVersion(10) to check whether version 10 is a
# bad version.
class Solution:
    """
    @param n: An integers.
    @return: An integer which is the first bad version.
    """
    def findFirstBadVersion(self, n):
        # write your code here
        l, h = 0, n
        while l < h:
            mid = (l+h)/2
            if VersionControl.isBadVersion(mid):
                h = mid
            else:
                l = mid + 1
        return l
