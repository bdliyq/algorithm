#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/search-in-rotated-sorted-array/

class Solution:
    """
    @param A : a list of integers
    @param target : an integer to be searched
    @return : an integer
    """
    def search(self, A, target):
        # write your code here
        left = 0
        right = len(A)-1
        while left <= right:
            mid = left + (right-left)/2
            if A[mid] == target:
                return mid
            elif A[mid] > A[left]:
                if A[mid] > target and target >= A[left]:
                    right = mid-1
                else:
                    left = mid+1
            else:
                if A[mid] < target and target <= A[right]:
                    left = mid+1
                else:
                    right = mid-1
        return -1

if __name__ == '__main__':
    s = Solution()
    print s.search([1,2,3,4,5,6], 2)
    print s.search([1,2,3,4,5,6], -1)
    print s.search([6,1,2,3,3,3,3,3,3,4,5], 4)
    print s.search([2,3,4,5,6,1], 3)
    print s.search([0,1,2,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1], -9)
