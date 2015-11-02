#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/median-of-two-sorted-arrays/

class Solution:
    def find_kth(self, A, B, k):
        if len(A) > len(B):
            return self.find_kth(B, A, k)
        if len(A) == 0:
            return B[k-1]
        if k == 1:
            return min(A[0], B[0])

        pa = min(k/2, len(A))
        pb = k-pa
        if A[pa-1] < B[pb-1]:
            return self.find_kth(A[pa:], B, k-pa)
        elif A[pa-1] > B[pb-1]:
            return self.find_kth(A, B[pb:], k-pb)
        else:
            return A[pa-1]

    """
    @param A: An integer array.
    @param B: An integer array.
    @return: a double whose format is *.5 or *.0
    """
    def findMedianSortedArrays(self, A, B):
        # write your code here
        total = len(A) + len(B)
        if total % 2 == 1:
            return self.find_kth(A, B, total/2+1)
        else:
            return (self.find_kth(A, B, total/2) + self.find_kth(A, B, total/2+1)) * 1.0 / 2

if __name__ == '__main__':
    s = Solution()
    print s.findMedianSortedArrays([1,2,3,4,5,6], [2,3,4,5])
