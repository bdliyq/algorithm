#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/add-and-search-word/

class TrieNode(object):
    def __init__(self):
        self.children = dict()
        self.is_end = False


class WordDictionary:
    # initialize your data structure here.
    def __init__(self):
        # Write your code here
        self.root = TrieNode()


    # @param {string} word
    # @return {void}
    # Adds a word into the data structure.
    def addWord(self, word):
        # Write your code here
        cursor = self.root
        for char in word:
            if not cursor.children.has_key(char):
                cursor.children[char] = TrieNode()
            cursor = cursor.children[char]
        cursor.is_end = True


    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the data structure. A word could
    # contain the dot character '.' to represent any one letter.
    def search(self, word):
        # Write your code here
        return self.__search(word, 0, self.root)

    def __search(self, word, pos, cursor):
        if pos == len(word):
            return cursor.is_end

        if word[pos] == '.':
            for k, v in cursor.children.items():
                if self.__search(word, pos+1, v):
                    return True
        else:
            if cursor.children.has_key(word[pos]):
                return self.__search(word, pos+1, cursor.children[word[pos]])

        return False


# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")

