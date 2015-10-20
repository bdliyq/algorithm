#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/remove-element/

class Solution:
    """
    @param A: A list of integers
    @param elem: An integer
    @return: The new length after remove
    """
    def removeElement(self, A, elem):
        # write your code here
        cursor = 0
        reader = 0
        while reader < len(A):
            while reader < len(A) and A[reader] == elem:
                reader += 1
            if reader < len(A):
                A[cursor] = A[reader]
                cursor += 1
                reader += 1

        return cursor

if __name__ == '__main__':
    s = Solution()
    array = [0,4,4,0,0,2,4,4]
    new_len = s.removeElement(array, 4)
    print new_len, array
