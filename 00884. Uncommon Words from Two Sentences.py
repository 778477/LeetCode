# /usr/bin/env python2
# -*- encoding: utf8 -*-

"""
    884. Uncommon Words from Two Sentences
    
    We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
    
    A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
    
    Return a list of all uncommon words.
    
    You may return the list in any order.
    
    
    
    Example 1:
    
    Input: A = "this apple is sweet", B = "this apple is sour"
    Output: ["sweet","sour"]
    Example 2:
    
    Input: A = "apple apple", B = "banana"
    Output: ["banana"]
    
    
    Note:
    
    0 <= A.length <= 200
    0 <= B.length <= 200
    A and B both contain only spaces and lowercase letters.
    """


"""
    53 / 53 test cases passed.
    Status: Accepted
    Runtime: 20 ms
    """

__author__ = "miaoyou.gmy"

import sys
import string
from collections import Counter

class Solution(object):
    def uncommonFromSentences(self, A, B):
        c = Counter(A.split(' ') + B.split(' '))
        return filter(lambda element: c[element] == 1,c.elements())


def main():
    solve = Solution()
    print solve.uncommonFromSentences("this apple is sweet","this apple is sour")
    return 0


if __name__ == "__main__":
    sys.exit(main())

