#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/interleaving-positive-and-negative-numbers/

class Solution:
    """
    @param A: An integer array.
    @return nothing
    """
    def rerange(self, A):
        # write your code here
        if len(A) == 0:
            return

        pos_cnt = 0
        i = 0
        j = 0

        # Put all positive numbers at front
        for j in xrange(len(A)):
            if A[j] > 0:
                A[i], A[j] = A[j], A[i]
                i += 1
                pos_cnt += 1

        i = 1  # Pointer of positive numbers
        j = 0  # Pointer of negative numbers
        if pos_cnt > len(A)/2:
            # If positive numbers are more than negative ones, put the first number as positive.
            # Besides, flip the array A.
            i = 0
            j = 1
            A.reverse()

        while True:
            while i < len(A) and A[i] > 0:
                i += 2
            while j < len(A) and A[j] < 0:
                j += 2
            if i >= len(A) or j >= len(A):
                break
            A[i], A[j] = A[j], A[i]


if __name__ == '__main__':
    s = Solution()
    arr = [28,2,-22,-27,2,9,-33,-4,-18,26,25,34,-35,-17,2,-2,32,35,-8]
    s.rerange(arr)
    print arr
