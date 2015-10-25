#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/count-of-smaller-number-before-itself/

class Solution:
    def lowbit(self, i):
        return i & -i

    def sum(self, C, i):
        s = 0
        while i > 0:
            s += C[i]
            i -= self.lowbit(i)
        return s

    def add(self, C, i, v):
        if i == 0:
            return

        while i < len(C):
            C[i] += v
            i += self.lowbit(i)

    """
    @param A: A list of integer
    @return: Count the number of element before this element 'ai' is
             smaller than it and return count number list
    """
    def countOfSmallerNumberII(self, A):
        # write your code here
        res = []
        C = [0 for i in xrange(10002)]
        for i in A:
            res.append(self.sum(C, i))
            # Offset by 1, st. sum function counts the number of element BEFORE this element(EXCLUDING itself).
            self.add(C, i+1, 1)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.countOfSmallerNumberII([1,2,2,7,8,5])
