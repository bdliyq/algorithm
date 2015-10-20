#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/palindrome-partitioning/

class Solution:
    def check(self, s):
        if len(s) <= 1:
            return True

        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1

        return True

    def work_with_recursion(self, s, path, results):
        if len(s) == 0:
            return

        if self.check(s):
            path_copy = path[:]
            path_copy.append(s)
            results.append(path_copy)

        for i in xrange(1, len(s)):
            if self.check(s[:i]):
                path_copy = path[:]
                path_copy.append(s[:i])
                self.work_with_recursion(s[i:], path_copy, results)

    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        # write your code here
        results = []
        path = []
        self.work_with_recursion(s, path, results)
        return results

if __name__ == '__main__':
    s = Solution()
    print s.partition('aab')
    print s.partition('abcba')
