/**
 Status: Accepted
 Runtime: 16 ms
 Submitted: 1 year, 3 months ago
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> set1;
        set<int> set2;
        
        for_each(nums1.begin(), nums1.end(), [&](const int num){
            set1.insert(num);
        });
        
        for_each(nums2.begin(), nums2.end(), [&](const int num){
            set2.insert(num);
        });
        
        for(set<int>::iterator iter = set1.begin() ; iter != set1.end(); ++iter){
            if(set2.count(*iter)){
                ans.push_back(*iter);
            }
        }
        
        return ans;
    }
};
