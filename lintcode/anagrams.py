#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/anagrams/

class Solution:
    # @param strs: A list of strings
    # @return: A list of strings
    def anagrams(self, strs):
        # write your code here
        table = {}
        for s in strs:
            t = tuple(sorted(tuple(s)))
            if table.has_key(t):
                table[t].append(s)
            else:
                table[t] = [s]

        res = []
        for k, v in table.items():
            if len(v) > 1:
                res.extend(v)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.anagrams(['lint', 'intl', 'inlt', 'code'])
