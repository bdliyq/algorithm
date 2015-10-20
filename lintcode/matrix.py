#!/usr/bin/env python
# encoding: utf-8

# Common utilities for matrix-related questions.

import sys

def print_matrix(matrix):
    res = ''

    row = len(matrix)
    if row == 0:
        print res
        return
    col = len(matrix[0])
    if col == 0:
        print res
        return

    for i in xrange(row):
        if len(res) > 0:
            res += '\n'

        for j in xrange(col):
            if len(res) > 0 and res[-1] != '\n':
                res += '\t'
            if matrix[i][j] == sys.maxint:
                res += '-'
            else:
                res += str(matrix[i][j])

    print res
