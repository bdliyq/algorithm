#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/permutation-sequence/

class Solution:
    """
    @param n: n
    @param k: the k-th permutation
    @return: a string, the k-th permutation
    """
    def getPermutation(self, n, k):
        if n < 1:
            return ''

        pool = [i for i in xrange(1, n+1)]
        s = 1
        for i in xrange(1, n):
            s *= i

        k -= 1
        ans = []
        for i in xrange(0, n-1):
            x = k/s
            ans.append(str(pool[x]))
            del pool[x]
            k %= s
            s /= (n-i-1)
        ans.append(str(pool[0]))

        return ''.join(ans)

if __name__ == '__main__':
    s = Solution()
    print s.getPermutation(3, 4)
