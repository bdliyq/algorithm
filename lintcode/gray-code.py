#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/gray-code/

class Solution:
    # @param {int} n a number
    # @return {int[]} Gray code
    def grayCode(self, n):
        # Write your code here

        result = [0]
        for i in xrange(n):
            count = len(result)
            for j in xrange(count - 1, -1, -1):
                result.append(result[j] | pow(2, i))
        return result

if __name__ == '__main__':
    s = Solution()
    print s.grayCode(0)
    print s.grayCode(1)
    print s.grayCode(2)
    print s.grayCode(3)
    print s.grayCode(4)
