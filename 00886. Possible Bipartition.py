
# /usr/bin/env python2
# -*- encoding: utf8 -*-

"""
886. Possible Bipartition

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group.

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.



Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false


Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
"""


"""
65 / 65 test cases passed.
Status: Accepted
Runtime: 208 ms
"""

__author__ = "miaoyou.gmy"

import sys
import string
from collections import Counter


class Solution:
    def dfs(self, graph, colors, node, c):
        if colors[node] != 0:
            return colors[node] == c
        colors[node] = c
        for i in graph[node]:
            if not self.dfs(graph, colors, i, -c):
                return False
        return True
    def possibleBipartition(self, N, dislikes):
        """
            :type N: int
            :type dislikes: List[List[int]]
            :rtype: bool
            """
        graph = [[] for i in range(N)]
        for dis in dislikes:
            u = dis[0]
            v = dis[1]
            graph[u-1].append(v-1)
            graph[v-1].append(u-1)
    
        colors = [i*0 for i in range(N)]
        
        for i in range(N):
            if colors[i] == 0 and not self.dfs(graph, colors, i, 1):
                return False

return True


def main():
    solve = Solution()
    print solve.possibleBipartition(3, [[1, 2], [1, 3], [2, 3]])
    
    pass
    return 0


if __name__ == "__main__":
    sys.exit(main())
