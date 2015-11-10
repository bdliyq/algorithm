#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/permutation-index-ii/

class Solution:
    def dup_perm(self, h):
        if not h:
            return 1

        dup = 1
        for k,v in h.items():
            dup *= self.w(v)
        return dup

    def w(self, n):
        ret = 1
        while n > 1:
            ret *= n
            n -= 1
        return ret

    # @param {int[]} A an integer array
    # @return {long} a long integer
    def permutationIndexII(self, A):
        # Write your code here
        if not A:
            return 0

        n = len(A)
        ans = 1
        factor = self.w(n-1)

        for i in xrange(0, len(A)):
            rank = 0
            for j in xrange(i+1, len(A)):
                if A[i] > A[j]:
                    rank += 1

            hm = {}
            for j in xrange(i, len(A)):
                if hm.has_key(A[j]):
                    hm[A[j]] += 1
                else:
                    hm[A[j]] = 1

            ans += factor * rank / self.dup_perm(hm)
            if i < n-1:
                factor /= (n-i-1)

        return ans

if __name__ == '__main__':
    s = Solution()
    print s.permutationIndexII([1,4,2,2])
