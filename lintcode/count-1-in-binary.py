#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/count-1-in-binary/

class Solution:
    # @param num: an integer
    # @return: an integer, the number of ones in num
    def countOnes(self, num):
        # write your code here
        res = 0
        if num < 0:
            res += 1
            num = abs(num)
        while num != 0:
            res += 1
            num &= (num-1)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.countOnes(5)
    print s.countOnes(32)
    print s.countOnes(1023)
    print s.countOnes(-1023)
