#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/backpack/

class Solution:
    def work_with_recursion(self, i, j, A):
        if i == 0 or j == 0:
            return 0

        if A[i-1] > j:
            return self.work_with_recursion(i-1, j, A)
        return max(self.work_with_recursion(i-1, j, A), self.work_with_recursion(i-1, j-A[i-1], A)+A[i-1])

    def work_with_dp(self, m, A):
        dp = [0 for i in xrange(m+1)]
        dp[0] = 1

        for i in xrange(len(A)):
            for j in xrange(m, -1, -1):
                if dp[j] == 1:
                    if j+A[i] <= m:
                        dp[j+A[i]] = 1

        for i in xrange(m, -1, -1):
            if dp[i] == 1:
                return i

    # @param m: An integer m denotes the size of a backpack
    # @param A: Given n items with size A[i]
    # @return: The maximum size
    def backPack(self, m, A):
        # write your code here
        return self.work_with_dp(m, A)
        # return self.work_with_recursion(len(A), m, A)

if __name__ == '__main__':
    s = Solution()
    print s.backPack(10, [3,4,8,5])
    print s.backPack(11, [2,3,5,7])
    print s.backPack(12, [2,3,5,7])
    print s.backPack(90, [12,3,7,4,5,13,2,8,4,7,6,5,7])
