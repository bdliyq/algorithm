#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/word-ladder/

import string

class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return an integer
    def ladderLength(self, start, end, dict):
        # write your code here
        alphabet = string.ascii_lowercase
        dict.add(end)
        queue = []
        queue.append((start, 1))
        while len(queue) > 0:
            word, dist = queue.pop(0)
            if word == end:
                return dist

            for j in alphabet:
                for i in xrange(len(word)):
                    if j != word[i]:
                        new_word = word[:i] + j + word[i+1:]
                        if new_word in dict:
                            dict.remove(new_word)
                            queue.append((new_word, dist + 1))
        return 0

if __name__ == '__main__':
    s = Solution()
    print s.ladderLength('hit', 'cog', set(["hot","dot","dog","lot","log"]))




