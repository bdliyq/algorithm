#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/search-insert-position/

class Solution:
    """
    @param A : a list of integers
    @param target : an integer to be inserted
    @return : an integer
    """
    def searchInsert(self, A, target):
        # write your code here
        if len(A) == 0:
            return 0

        l, h = 0, len(A)-1
        while l <= h:
            mid = (l+h)/2
            if target == A[mid]:
                return mid
            if target > A[mid]:
                l = mid+1
            else:
                h = mid-1

        return l

if __name__ == '__main__':
    s = Solution()
    print s.searchInsert([1,3,5,6], 0)
    print s.searchInsert([1,3,5,6], 1)
    print s.searchInsert([1,3,5,6], 2)
    print s.searchInsert([1,3,5,6], 4)
    print s.searchInsert([1,3,5,6], 6)
    print s.searchInsert([1,3,5,6], 7)
