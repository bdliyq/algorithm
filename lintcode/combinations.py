#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/combinations/

class Solution:
    """
    @param n: Given the range of numbers
    @param k: Given the numbers of combinations
    @return: All the combinations of k numbers out of 1..n
    """
    def combine(self, n, k):
        # write your code here
        if k == 0:
            return []

        stack = []
        for i in xrange(1, n+1):
            stack.append([i])

        res = []
        while stack:
            rs = stack.pop()
            if len(rs) == k:
                res.append(rs)
            else:
                for i in xrange(rs[-1]+1, n+1):
                    rs_copy = rs[:]
                    rs_copy.append(i)
                    stack.append(rs_copy)

        return res

if __name__ == '__main__':
    s = Solution()
    print s.combine(4, 2)

