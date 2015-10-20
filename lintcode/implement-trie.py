#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/implement-trie/

"""
Your Trie object will be instantiated and called as such:
trie = Trie()
trie.insert("lintcode")
trie.search("lint") will return false
trie.startsWith("lint") will return true
"""
class TrieNode:
    def __init__(self):
        # Initialize your data structure here.
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word):
        if len(word) == 0:
            return

        node = self.root
        for i in xrange(len(word)):
            c = word[i]
            if node.children.has_key(c):
                if i == len(word) - 1:
                    node.children[c] = (node.children[c][0], True)
                else:
                    node = node.children[c][0]
            else:
                new_node = TrieNode()
                if i == len(word) - 1:
                    node.children[c] = (new_node, True)
                else:
                    node.children[c] = (new_node, False)
                node = node.children[c][0]

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word):
        if len(word) == 0:
            return False

        node = self.root
        for i in xrange(len(word)):
            c = word[i]
            if not node.children.has_key(c):
                return False
            else:
                node, is_end = node.children[c]
                if i == len(word) - 1:
                    return is_end

        return False

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix):
        if len(prefix) == 0:
            return False

        node = self.root
        for i in xrange(len(prefix)):
            c = prefix[i]
            if not node.children.has_key(c):
                return False
            else:
                node, is_end = node.children[c]
                if i == len(prefix) - 1:
                    return True

        return False

if __name__ == '__main__':
    trie = Trie()
    trie.insert('a')
    trie.insert('b')
    trie.insert('c')
    print trie.startsWith('a')
    print trie.search('b')
    trie.insert('b')
    trie.insert('b')
    trie.insert('b')
    print trie.search('b')
    # trie.insert("lintcode")
    # print trie.search("lint") # will return false
    # print trie.startsWith("lint") # will return true
