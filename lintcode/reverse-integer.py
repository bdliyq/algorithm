#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/reverse-integer/

class Solution:
    # @param {int} n the integer to be reversed
    # @return {int} the reversed integer
    def reverseInteger(self, n):
        # Write your code here
        sign = 1
        if n < 0:
            sign = -1
            n = -1 * n

        res = 0
        while n > 0:
            t = n % 10
            res = res * 10 + t
            if res & 0x7FFFFFFF != res:
                return 0
            n /= 10
        return res * sign

if __name__ == '__main__':
    s = Solution()
    print s.reverseInteger(100)
    print s.reverseInteger(-200)
    print s.reverseInteger(-123)


