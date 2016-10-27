
//Accepted	344 ms	java
public class Solution {
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        midLeftRight(root,ans);
        
        return ans;
    }
    
    public void midLeftRight(TreeNode root,ArrayList<Integer> ans)
    {
        if(root == null) return ;
        midLeftRight(root.left, ans);
        ans.add(root.val);
        midLeftRight(root.right, ans);
    }
}
