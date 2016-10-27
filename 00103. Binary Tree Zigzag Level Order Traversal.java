
//Accepted	404 ms	java
import java.util.*;

public class Solution {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> ans = new ArrayList<List<Integer>>();

		if(root == null) return ans;
		
		this.level = 0;

		dfs_level(root, 0);

		for (int i = 0; i <= this.level; i++) {
			ans.add(new ArrayList<Integer>());
		}

		dfs(root, 0, ans);

		for (int i = 1; i <= level; i += 2)
			Collections.reverse(ans.get(i));

		return ans;
	}

	public void dfs_level(TreeNode root, int step) {
		if (root == null)
			return;

		this.level = Math.max(step, this.level);

		dfs_level(root.left, step + 1);
		dfs_level(root.right, step + 1);
	}

	public void dfs(TreeNode root, int step, List<List<Integer>> ans) {
		if (root == null)
			return;

		ans.get(step).add(root.val);

		dfs(root.left, step + 1, ans);
		dfs(root.right, step + 1, ans);
	}

	private int level;
}
