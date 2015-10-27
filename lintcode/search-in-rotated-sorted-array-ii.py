#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/search-in-rotated-sorted-array-ii/

class Solution:
    """
    @param A : an integer ratated sorted array and duplicates are allowed
    @param target : an integer to be searched
    @return : a boolean
    """
    def search(self, A, target):
        # write your code here
        left = 0
        right = len(A)-1
        while left <= right:
            mid = left + (right-left)/2
            if A[mid] == target:
                return True
            elif A[mid] > A[left]:
                if A[left] <= target and target < A[mid]:
                    right = mid-1
                else:
                    left = mid+1
            elif A[mid] < A[right]:
                if A[mid] < target and target <= A[right]:
                    left = mid+1
                else:
                    right = mid-1
            else:
                while left < len(A) and A[left] == A[mid]:
                    left += 1
                while right >= 0 and A[right] == A[mid]:
                    right -= 1
        return False

if __name__ == '__main__':
    s = Solution()
    print s.search([0,1,-9,-9,-9,-9,-7,-6,-5,-4,-3,-2,-1], -9)

