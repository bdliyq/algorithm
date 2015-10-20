#!/usr/bin/env python
# encoding: utf-8

# Question: 一个Dictionary，一个String，把String中去掉0或者任意多个character，得到一个字典中存在的String，求这样最长的String。

class Solution(object):
    def solve(self, s, d):
        queue = [s]
        while queue:
            word = queue.pop(0)
            if len(word) == 0:
                continue
            if word in d:
                return len(word)
            for i in xrange(len(word)):
                queue.append(word[:i] + word[i+1:])
        return -1

if __name__ == '__main__':
    s = Solution()
    print s.solve('abcdefg', set(['a','b','c','abcd','abcdz','cdefg']))
    print s.solve('abcdefg', set(['az','bz','cz','abcdz','abcdz','cdefgz']))
