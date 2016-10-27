
//Accepted	444 ms	java
public class Solution {
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        if(root == null)
            return ans;      
        this.level = 0;
        dfs_level(root,0);
        for(int i=0;i<=level;i++)
        {
            ans.add(new ArrayList<Integer>());
        }
        dfs(root,ans,0);
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        int len = ans.size()-1;
        for(int i=len;i>-1;i--)
        {
            res.add(ans.get(i));
        }
        return res;
    }
    
    public void dfs_level(TreeNode rt,int step)
    {
        if(rt == null) return ;
        if(step > this.level) this.level = step;
        dfs_level(rt.left,step+1);
        dfs_level(rt.right, step+1);
    }
    
    public void dfs(TreeNode rt,ArrayList<ArrayList<Integer>> ans,int step)
    {
        if(rt == null) return ;
        ans.get(step).add(rt.val);
        dfs(rt.left,ans,step+1);
        dfs(rt.right,ans,step+1);
    }
    
    private int level;
}
