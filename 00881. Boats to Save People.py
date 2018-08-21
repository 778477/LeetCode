# /usr/bin/env python2
# -*- encoding: utf8 -*-

"""

881. Boats to Save People
DescriptionHintsSubmissionsDiscussSolution
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
Note:

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000

"""


"""

77 / 77 test cases passed.
Status: Accepted
Runtime: 148 ms

"""

__author__ = "miaoyou.gmy"

import sys
import collections


class Solution(object):
    def numRescueBoats(self, people, limit):
        people.sort()
        ans = 0
        left = 0
        right = len(people) - 1
        while left <= right:
            while left < right and people[left] + people[right] > limit:
                ans += 1
                right -= 1
            if left < right and people[left] + people[right] <= limit:
                left += 1
                ans += 1
                right -= 1
            elif left == right:
                ans += 1
                left += 1
                right -= 1
        return ans


def main():
    solve = Solution()
    peoples = [1, 2]
    print solve.numRescueBoats(peoples, 3)

    return 0


if __name__ == "__main__":
    sys.exit(main())
