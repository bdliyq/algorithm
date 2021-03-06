#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/subsets-ii/

class Solution:
    def work_with_recursion(self, s, path, res):
        res.append(path[:])
        if len(s) == 0:
            return

        subset = set()
        for i in xrange(len(s)):
            if s[i] in subset:
                continue
            path.append(s[i])
            self.work_with_recursion(s[i+1:], path, res)
            path.pop()
            subset.add(s[i])

    def work_with_iteration(self, s):
        ans = [[]]

        for c in s:
            count = len(ans)
            for i in xrange(count):
                ac = ans[i][:]
                ac.append(c)
                if not ac in ans:
                    ans.append(ac)

        return ans

    """
    @param S: A set of numbers.
    @return: A list of lists. All valid subsets.
    """
    def subsetsWithDup(self, S):
        # write your code here
        # res = []
        # self.work_with_recursion(sorted(S), [], res)
        # return res
        return self.work_with_iteration(sorted(S))

if __name__ == '__main__':
    s = Solution()
    print s.subsetsWithDup([1,2,2])

