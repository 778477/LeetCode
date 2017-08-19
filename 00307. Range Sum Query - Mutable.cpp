/**
 Status: Accepted
 Runtime: 1892 ms
 Submitted: 1 year, 6 months ago
*/
typedef unsigned long lusigned;

struct SegmenTreeNode{
    int val;
    lusigned star,end;
    SegmenTreeNode *left,*right;
    SegmenTreeNode(lusigned _star,lusigned _end,int _val){
        val = _val;
        star = _star, end = _end;
        left = right = NULL;
    }
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        numbers = nums;
        if(nums.size() >= 1){
            rootNode = buildSegmentTree(0, 0, nums.size()-1, nums);
        }
    }
    
    void update(int i, int val){
        updateNodeVal(rootNode, i, val);
    }
    
    int sumRange(int i, int j) {
        if(j < i) return 0;
        return querySumValInSegmentTree(rootNode, 0, numbers.size()-1, i, j);
    }
    
private:
    vector<int> numbers;
    SegmenTreeNode *rootNode;
    SegmenTreeNode *buildSegmentTree(int root,lusigned star,lusigned end,const vector<int> nums){
        
        SegmenTreeNode *rootNode = new SegmenTreeNode(star, end, 0);
        
        if(star == end){
            rootNode->val = nums[star];
        }
        else{
            lusigned mid = (star + end)/2;
            rootNode->left = buildSegmentTree(root*2+1, star, mid, nums);
            rootNode->right =  buildSegmentTree(root*2+2, mid+1, end, nums);
            
            rootNode->val = rootNode->left->val + rootNode->right->val;
        }
        
        return rootNode;
    }
    
    int updateNodeVal(SegmenTreeNode *root, int idx,int value){
        if(root->star == root->end && root->star == idx)  return (root->val = value);
        else if(root->star == root->end) return root->val;
        
        lusigned mid = (root->star + root->end)>>1;
        if(idx <= mid){
            root->left->val = updateNodeVal(root->left, idx, value);
        }
        else{
            root->right->val = updateNodeVal(root->right, idx, value);
        }
        return (root->val = root->left->val + root->right->val);
    }
    
    int querySumValInSegmentTree(SegmenTreeNode *root, lusigned star,lusigned end,lusigned qSidx,lusigned qEidx){
        
        if(qSidx <= star && qEidx >= end) return root->val;
        
        if(qEidx < star || qSidx > end) return 0;
        
        lusigned mid = (star + end) / 2;
        
        int leftSumVal = querySumValInSegmentTree(root->left, star, mid, qSidx, qEidx);
        int rightSumVal = querySumValInSegmentTree(root->right, mid+1, end, qSidx, qEidx);
        
        return leftSumVal + rightSumVal;
    }
};

