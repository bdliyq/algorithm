#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/first-missing-positive/

class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        # write your code here
        if len(A) == 0:
            return 1

        for k in xrange(len(A)):
            while A[k] != k+1 and A[k] > 0 and A[k] <= len(A) and A[k] != A[A[k]-1]:
                t = A[A[k]-1]
                A[A[k]-1] = A[k]
                A[k] = t

        i = 0
        while i < len(A):
            if A[i] != i+1:
                return i+1
            i += 1
        if i >= len(A):
            return i+1
        return 0

if __name__ == '__main__':
    s = Solution()
    print s.firstMissingPositive([2,1])
    print s.firstMissingPositive([3,4,-1,1])
    print s.firstMissingPositive([1,2,0])
    print s.firstMissingPositive([1])
    print s.firstMissingPositive([10])
