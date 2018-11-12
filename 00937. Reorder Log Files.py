# /usr/bin/env python2
# -*- encoding: utf8 -*-


"""

https://leetcode.com/problems/reorder-log-files/

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Note:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.


"""



"""

61 / 61 test cases passed.
Status: Accepted
Runtime: 68 ms

"""

__author__ = "miaoyou.gmy"

import string
import sys
import string
from collections import Counter


class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        ans = []

        letter = []
        digit = []

        for _,val in enumerate(logs):
            words = val.split(' ')
            if words[1].isdigit():
                digit.append(val)
            else:
                letter.append({'cmpVal':' '.join(words[1:]),'val':val})

        orderLetters = sorted(letter, key = lambda e:(e.__getitem__('cmpVal')))

        for i in range(len(orderLetters)):
            ans.append(orderLetters[i]['val'])

        for i in range(len(digit)):
            ans.append(digit[i])

        return ans
        


def main():
    solve = Solution()
    ans = solve.reorderLogFiles(["j mo", "5 m w", "g 07", "o 2 0", "t q h"])
    print ans
    return 0


if __name__ == "__main__":
    sys.exit(main())
