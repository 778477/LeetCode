
//	Accepted	352 ms	java
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null && q!=null) return false;
        if(p!=null && q==null) return false;
        if(p==null && q==null) return true;
        if(p.val == q.val)
        {
            if(isSameTree(p.left,q.left) && isSameTree(p.right,q.right)) return true;
        }
        return false;
    }
}
