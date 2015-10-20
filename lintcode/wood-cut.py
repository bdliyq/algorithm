#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/wood-cut/

import sys

class Solution:
    def find_longest(self, L):
        longest = -sys.maxint
        for l in L:
            longest = max(longest, l)
        return longest

    def find_cut(self, L, l):
        piece = 0
        for i in L:
            piece += i/l
        return piece

    """
    @param L: Given n pieces of wood with length L[i]
    @param k: An integer
    return: The maximum length of the small pieces.
    """
    def woodCut(self, L, k):
        # write your code here
        if len(L) == 0:
            return 0

        min_left = sys.maxint
        longest = self.find_longest(L)
        low = 0
        high = longest
        while low < high:
            mid = (low + high) / 2
            if mid == 0:
                return 0

            piece = self.find_cut(L, mid)
            if piece >= k:
                low = mid + 1
            else:
                high = mid

        return low - 1




if __name__ == '__main__':
    s = Solution()
    print s.woodCut([232, 124, 456], 7)
