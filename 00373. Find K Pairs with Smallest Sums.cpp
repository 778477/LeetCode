/*
[Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)


重点在于使用优先队列(堆 数据结构),定义 比较函数。

时间复杂度是 `O(Klog(N))`,空间复杂度是 `O(N)`

```
K = min(k,nm)
N = min(k,n)
m,n 是题中array的长度。
```

*/

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        
        if(k < 1 || nums1.empty() || nums2.empty()) return ans;
        
        
        auto comp = [&nums1,&nums2](pair<int, int> a, pair<int, int> b){
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        
        minHeap.emplace(0,0);
        while(!minHeap.empty() && k > 0){
            k--;
            auto topPair = minHeap.top();
            minHeap.pop();
            ans.push_back(make_pair(nums1[topPair.first], nums2[topPair.second]));
            
            if(topPair.first + 1 < nums1.size()){
                minHeap.emplace(topPair.first+1,topPair.second);
            }
            
            if(topPair.first == 0 && topPair.second + 1 < nums2.size()){
                minHeap.emplace(topPair.first,topPair.second+1);
            }
        }
        
        return ans;
    }
};

