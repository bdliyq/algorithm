#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/k-sum-ii/

class Solution:
    def helper(self, A, k, target, path, ans, istart):
        if k == 0 and target == 0:
            ans.append(path[:])
            return
        elif len(A) - istart < k or target < 0:
            return

        for i in xrange(istart, len(A)):
            path_copy = path[:]
            path_copy.append(A[i])
            self.helper(A, k-1, target-A[i], path_copy, ans, i+1)

    def helper2(self, A, k, target, path, ans, istart):
        if k == 0 and target == 0:
            ans.append(path)
            return
        elif k == 0 and target != 0:
            return
        elif len(A) - istart < k or target < 0:
            return

        self.helper2(A, k, target, path[:], ans, istart+1)
        path_copy = path[:]
        path_copy.append(A[istart])
        self.helper2(A, k-1, target-A[istart], path_copy, ans, istart+1)

    """
    @param A: An integer array.
    @param k: A positive integer (k <= length(A))
    @param target: Integer
    @return a list of lists of integer
    """
    def kSumII(self, A, k, target):
        # write your code here
        ans = []
        self.helper2(A, k, target, [], ans, 0)
        return ans

if __name__ == '__main__':
    s = Solution()
    # print s.kSumII([1,2,3,4], 2, 5)
    print s.kSumII([1,3,6,7,10,12,15,16,17,18,20,22,25,28,30,32,35,37,39,42,43,45], 5, 123)
