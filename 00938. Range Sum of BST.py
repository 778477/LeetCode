# /usr/bin/env python2
# -*- encoding: utf8 -*-


"""

https://leetcode.com/problems/range-sum-of-bst/

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23
 

Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.


"""



"""

42 / 42 test cases passed.
Status: Accepted
Runtime: 440 ms

"""

__author__ = "miaoyou.gmy"

import string
import sys
import string
from collections import Counter

# Definition for a binary tree node.
class TreeNode():
     def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution():
    def dfs(self, root, L, R, ans):
        if not root:
            return 0

        ans = 0
        if root.val >= L and root.val <= R:
            ans += root.val
        
        if root.val <= L:
            ans += self.dfs(root.left, L, R, 0)

        if root.val >= R:
            ans += self.dfs(root.right, L, R, 0)

        return ans

    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        return self.dfs(root, L, R, 0)
        

def main():
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(15)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(7)
    root.right.right = TreeNode(18)

    solve = Solution()
    print solve.rangeSumBST(root,7,15)


    return 0


if __name__ == "__main__":
    sys.exit(main())
