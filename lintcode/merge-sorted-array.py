#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/merge-sorted-array/

class Solution:
    """
    @param A: sorted integer array A which has m elements,
              but size of A is m+n
    @param B: sorted integer array B which has n elements
    @return: void
    """
    def mergeSortedArray(self, A, m, B, n):
        # write your code here
        i, j = m-1, n-1
        cursor = m+n-1
        while i >= 0 and j >= 0:
            if A[i] < B[j]:
                A[cursor] = B[j]
                j -= 1
                cursor -= 1
            elif A[i] == B[j]:
                A[cursor] = A[i]
                i -= 1
                cursor -= 1
                A[cursor] = B[j]
                j -= 1
                cursor -= 1
            else:
                A[cursor] = A[i]
                i -= 1
                cursor -= 1
        while i >= 0:
            A[cursor] = A[i]
            i -= 1
            cursor -= 1
        while j >= 0:
            A[cursor] = B[j]
            j -= 1
            cursor -= 1

if __name__ == '__main__':
    s = Solution()
    A = [1, 2, 3, 0, 0]
    B = [-1, -2]
    s.mergeSortedArray(A, 3, B, 2)
    print A


