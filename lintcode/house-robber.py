#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/house-robber/

class Solution:
    # @param A: a list of non-negative integers.
    # return: an integer
    def houseRobber(self, A):
        # write your code here
        if len(A) == 0:
            return 0

        i = 0
        j = 0

        for x in A:
            if i == j:
                i, j = j, j+x
            else:
                i, j = j, max(j, i+x)

        return j

if __name__ == '__main__':
    s = Solution()
    print s.houseRobber([3,8,4,9,1,1,1,3])




