#!/usr/bin/env python
# encoding: utf-8

# Question:
# 给一个array比如[4,2,1,3,5],根据这个array现在我们能有了一个新的array => 每数是在原array里, 在它左边的所有比它大的number的个数,就是[0,1,2,1,0]. 题目是现在给了这个[0,1,2,1,0]要求原array, 原来array的range是1~n

class Solution(object):
    def solve(self, A):
        result = [0 for i in xrange(len(A))]
        array = [i for i in xrange(1, len(A)+1)]

        for i in xrange(len(A)-1, -1, -1):
            result[i] = array[i - A[i]]
            del array[i-A[i]]

        return result

if __name__ == '__main__':
    s = Solution()
    print s.solve([0,1,2,1,0])
