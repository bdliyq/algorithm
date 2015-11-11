#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/digit-counts/

class Solution:
    # @param k & n  two integer
    # @return ans a integer
    def digitCounts(self, k, n):
        ans = 0
        base = 1
        while base <= n:
            part1 = n/(base*10)
            if base > 1 and k == 0 and part1 > 0:
                part1 -= 1
            part1 *= base
            bar = n/base%10
            part2 = 0
            if k < bar:
                part2 = base
            elif k == bar:
                part2 = n%base + 1
            if k == 0 and n < base * 10:
                part2 = 0
            ans += part1 + part2
            base *= 10
        return ans
