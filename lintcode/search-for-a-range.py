#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/search-for-a-range/

class Solution:
    def helper(self, A, target, start, end):
        if len(A) == 0:
            return [-1, -1]

        l = start
        r = end
        while l <= r:
            m = l + (r-l)/2
            if A[m] == target:
                ll, lr = self.helper(A, target, l, m-1)
                rl, rr = self.helper(A, target, m+1, r)
                if ll == -1 and rr == -1:
                    return [m, m]
                elif ll == -1:
                    return [m, rr]
                elif rr == -1:
                    return [ll, m]
                else:
                    return [ll, rr]
            elif A[m] < target:
                l = m+1
            else:
                r = m-1
        return [-1, -1]

    """
    @param A : a list of integers
    @param target : an integer to be searched
    @return : a list of length 2, [index1, index2]
    """
    def searchRange(self, A, target):
        # write your code here
        return self.helper(A, target, 0, len(A)-1)

if __name__ == '__main__':
    s = Solution()
    print s.searchRange([5,5,5,5,5,5,5,5,5,5], 5)
    print s.searchRange([5, 7, 7, 8, 8, 10], 8)


