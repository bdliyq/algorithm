#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/longest-consecutive-sequence/

class Solution:
    """
    @param num, a list of integer
    @return an integer
    """
    def longestConsecutive(self, num):
        # write your code here
        s = set(num)
        res = 0
        for i in num:
            if i in s:
                r = 1
                j = i+1
                while j in s:
                    s.remove(j)
                    r += 1
                    j += 1
                j = i-1
                while j in s:
                    s.remove(j)
                    r += 1
                    j -= 1
                s.remove(i)
                res = max(res, r)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.longestConsecutive([100, 4, 200, 1, 3, 2])
