#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/word-search/

import copy

class Solution:
    def dfs(self, board, word, path, x, y, i):
        if (x, y) in path:
            return False

        if i + 1 == len(word):
            return True

        path.add((x, y))
        if x + 1 >= 0 and x + 1 < len(board) and board[x + 1][y] == word[i + 1] and self.dfs(board, word, path, x + 1, y, i + 1):
            return True
        if x - 1 >= 0 and x - 1 < len(board) and board[x - 1][y] == word[i + 1] and self.dfs(board, word, path, x - 1, y, i + 1):
            return True
        if y + 1 >= 0 and y + 1 < len(board[0]) and board[x][y + 1] == word[i + 1] and self.dfs(board, word, path, x, y + 1, i + 1):
            return True
        if y - 1 >= 0 and y - 1 < len(board[0]) and board[x][y - 1] == word[i + 1] and self.dfs(board, word, path, x, y - 1, i + 1):
            return True
        path.remove((x, y))

        return False

    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    def exist(self, board, word):
        # write your code here
        if len(board) == 0 or len(board[0]) == 0:
            return False

        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if board[i][j] == word[0]:
                    path = set()
                    if self.dfs(board, word, path, i, j, 0):
                        return True

        return False

if __name__ == '__main__':
    s = Solution()
    print s.exist(["ABCE","SFCS","ADEE"], "ABCB")
    print s.exist(["ABCE","SFCS","ADEE"], "ABCCED")


