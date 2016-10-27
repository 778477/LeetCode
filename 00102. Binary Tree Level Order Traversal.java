
//	Accepted	420 ms	java
public class Solution {
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
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
        return ans;
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
//        for(ArrayList<Integer> array : ans)
//            System.out.println(array);
//        System.out.println("\n");
        ans.get(step).add(rt.val);
        dfs(rt.left,ans,step+1);
        dfs(rt.right,ans,step+1);
    }
    
    private int level;
}
