#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/lru-cache/

class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        # write your code here
        self.l = []
        self.d = {}
        self.c = capacity

    # @return an integer
    def get(self, key):
        # write your code here
        if self.d.has_key(key):
            self.l.remove(key)
            self.l.append(key)
            return self.d[key]
        return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        # write your code here
        if self.d.has_key(key):
            self.l.remove(key)
            self.l.append(key)
            self.d[key] = value
        else:
            self.l.append(key)
            self.d[key] = value
            if len(self.l) > self.c:
                k = self.l.pop(0)
                del self.d[k]

if __name__ == '__main__':
    s = LRUCache(3)
    s.set('a', 10)
    s.set('b', 20)
    s.set('c', 30)
    s.set('d', 40)
    s.set('e', 50)
    print s.get('a')
    print s.get('d')
