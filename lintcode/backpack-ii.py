#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/backpack-ii/

class Solution:
    def work_with_recursion(self, i, j, A, V):
        if i == 0 or j == 0:
            return 0

        if A[i-1] > j:
            return self.work_with_recursion(i-1, j, A, V)
        return max(self.work_with_recursion(i-1, j, A, V), V[i-1] + self.work_with_recursion(i-1, j-A[i-1], A, V))

    def work_with_dp(self, m, A, V):
        dpvalue = [0 for i in xrange(m+1)]
        dpsize = [0 for i in xrange(m+1)]
        dpsize[0] = 1

        res = 0
        for i in xrange(len(A)):
            for j in xrange(m, -1, -1):
                if dpsize[j] == 1:
                    if j+A[i] <= m:
                        dpsize[j+A[i]] = 1
                        dpvalue[j+A[i]] = max(dpvalue[j+A[i]], dpvalue[j]+V[i])
                        res = max(res, dpvalue[j+A[i]])

        return res

    # @param m: An integer m denotes the size of a backpack
    # @param A & V: Given n items with size A[i] and value V[i]
    # @return: The maximum value
    def backPackII(self, m, A, V):
        # write your code here
        # return self.work_with_recursion(len(A), m, A, V)
        return self.work_with_dp(m, A, V)

if __name__ == '__main__':
    s = Solution()
    print s.backPackII(10, [2,3,5,7], [1,5,2,4])
