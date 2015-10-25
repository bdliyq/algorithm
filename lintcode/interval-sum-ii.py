#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/interval-sum-ii/

class Solution:

    # @param A: An integer list
    def __init__(self, A):
        # write your code here
        self.A = A
        self.C = [0 for i in xrange(len(A)+1)]
        for i in xrange(len(self.A)):
            self.add(i+1, self.A[i])

    # @param start, end: Indices
    # @return: The sum from start to end
    def query(self, start, end):
        # write your code here
        return self.sum(end+1) - self.sum(start)

    # @param index, value: modify A[index] to value.
    def modify(self, index, value):
        # write your code here
        self.add(index+1, value - self.A[index])
        self.A[index] = value
        # Or: self.add(index+1, value - self.query(index, index)), st. we can ignore modify A[index], and further, we can avoid from saving A as a member of class.

    def lowbit(self, i):
        return i & -i

    def add(self, i, v):
        if i == 0:
            return
        while i < len(self.C):
            self.C[i] += v
            i += self.lowbit(i)

    def sum(self, i):
        sum = 0
        while i > 0:
            sum += self.C[i]
            i -= self.lowbit(i)
        return sum

if __name__ == '__main__':
    s = Solution([1,2,7,8,5])
    print s.query(0,2)
    s.modify(4,10)
    print s.query(3,4)
    s.modify(2,1)
    print s.query(2,4)

