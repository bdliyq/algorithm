#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-array/

class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates(self, A):
        # write your code here
        if len(A) <= 1:
            return len(A)

        writer = 0
        reader = 1
        while reader < len(A):
            while reader < len(A) and A[reader] == A[writer]:
                reader += 1
            if reader < len(A):
                writer += 1
                A[writer] = A[reader]

        return writer + 1

if __name__ == '__main__':
    s = Solution()
    array = [1,1,2]
    length = s.removeDuplicates(array)
    print length, array
