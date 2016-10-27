/*
[ Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)



和[373. Find K Pairs with Smallest Sums](https://github.com/778477/LeetCode/blob/master/373.%20Find%20K%20Pairs%20with%20Smallest%20Sums.md)解题思路一致，略费内存！

*/

class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        size_t n = matrix.size();
        vector<int> ans;
        
        auto comp = [&matrix](pair<int, int> a, pair<int, int> b){
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        
        minHeap.emplace(0,0);
        while(k > 0){
            k--;
            auto topPair = minHeap.top();
            minHeap.pop();
            ans.push_back(matrix[topPair.first][topPair.second]);
            
            if(topPair.first + 1 < n){
                minHeap.emplace(topPair.first+1,topPair.second);
            }
            
            if(topPair.first == 0 && topPair.second + 1 < n){
                minHeap.emplace(topPair.first,topPair.second+1);
            }
        }
        
        return ans.back();
    }
    
    
};
