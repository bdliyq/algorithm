#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-array-ii/

class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates(self, A):
        # write your code here
        if len(A) <= 2:
            return len(A)

        writer = 1
        reader = 2
        while reader < len(A):
            old_reader = reader
            while reader < len(A) and A[reader] == A[writer]:
                reader += 1
            if old_reader == reader:
                writer += 1
                A[writer] = A[reader]
                reader += 1
            else:
                if A[writer - 1] != A[writer]:
                    writer += 1
                    A[writer] = A[old_reader]
                if reader < len(A):
                    writer += 1
                    A[writer] = A[reader]
                    reader += 1

        return writer + 1

if __name__ == '__main__':
    array = [1,1,1,2,2,3,3,3]
    # array = [-8,0,1,2,3]
    s = Solution()
    length = s.removeDuplicates(array)
    print length, array

