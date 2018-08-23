# /usr/bin/env python2
# -*- encoding: utf8 -*-

"""

890. Find and Replace Pattern

You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20

"""


"""

46 / 46 test cases passed.
Status: Accepted
Runtime: 24 ms

"""
__author__ = "miaoyou.gmy"

import sys
import string
from collections import Counter

class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        def match(word):
            m1 = {}
            m2 = {}
            for w,p in zip(word,pattern):
                if w not in m1: m1[w] = p
                if p not in m2: m2[p] = w
                if (m1[w],m2[p]) != (p,w):
                    return False
            return True

        return filter(match,words)


def main():
    solve = Solution()
    print solve.findAndReplacePattern(
        ["yzmyr","fhufq","lghlq","oahot","ueiuq"],"iusiq")
    return 0


if __name__ == "__main__":
    sys.exit(main())
