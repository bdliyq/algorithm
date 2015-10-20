#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/trailing-zeros/

class Solution:
    # @param n a integer
    # @return ans a integer
    def trailingZeros(self, n):
        base = 5
        count = 0

        while n > 0:
            count += n / base
            n /= base

        return count

if __name__ == '__main__':
    s = Solution()
    print s.trailingZeros(11)
