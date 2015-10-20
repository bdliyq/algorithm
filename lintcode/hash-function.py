#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/hash-function/

class Solution:
    """
    @param key: A String you should hash
    @param HASH_SIZE: An integer
    @return an integer
    """
    def hashCode(self, key, HASH_SIZE):
        # write your code here
        magic_num = 33
        res = 0
        pows = [0 for i in xrange(len(key))]
        pows[0] = 1
        for i in xrange(1, len(key)):
            pows[i] = (pows[i-1] * magic_num) % HASH_SIZE

        for i in xrange(len(key)):
            c = key[i]
            res = (res + ord(c) * pows[len(key)-i-1]) % HASH_SIZE
        return res

if __name__ == '__main__':
    s = Solution()
    print s.hashCode('abcd', 100)
