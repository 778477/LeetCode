/**
 421 / 421 test cases passed.
 Status: Accepted
 Runtime: 32 ms
 Submitted: 1 week, 4 days ago
*/
class Solution {
public:
    void dfs(TreeNode *root, vector<int>& nums){
        if(!root) return;
        
        dfs(root->left,nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        dfs(root,nums);
        
        if(nums.size() < 1) return false;
        unsigned long i = 0, j = nums.size() - 1;
        
        while(i < j){
            if(nums[i] + nums[j] == k) return true;
            else if(nums[i] + nums[j] < k) ++i;
            else --j;
        }
        
        return false;
    }
};
