#!/usr/bin/env python
# encoding: utf-8
# Question: http://www.lintcode.com/en/problem/flip-bits/

class Solution:
    """
    @param a, b: Two integer
    return: An integer
    """
    def bitSwapRequired(self, a, b):
        # write your code here
        count = 0
        if ((a >> 31) & 1) ^ ((b >> 31) & 1) == 1:
            count += 1

        a &= 0x7FFFFFFF
        b &= 0x7FFFFFFF

        while a > 0 and b > 0:
            if (a & 1) ^ (b & 1) == 1:
                count += 1
            a >>= 1
            b >>= 1

        c = (a == 0) and b or a
        while c > 0:
            if c & 1 == 1:
                count += 1
            c >>= 1

        return count

if __name__ == '__main__':
    s = Solution()
    print s.bitSwapRequired(1, -1)
    print s.bitSwapRequired(31, 14)
