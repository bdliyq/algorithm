#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/product-of-array-exclude-itself/

class Solution:
    """
    @param A: Given an integers array A
    @return: An integer array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
    """
    def productExcludeItself(self, A):
        # write your code here
        a1 = [1 for i in xrange(len(A))]
        a2 = [1 for i in xrange(len(A))]

        for i in xrange(1, len(A)):
            a1[i] = a1[i-1] * A[i-1]
        for i in xrange(len(A)-2, -1, -1):
            a2[i] = a2[i+1] * A[i+1]

        res = [1 for i in xrange(len(A))]
        for i in xrange(0, len(A)):
            res[i] = a1[i] * a2[i]
        return res

if __name__ == '__main__':
    s = Solution()
    print s.productExcludeItself([1,2,3])
    print s.productExcludeItself([0])

