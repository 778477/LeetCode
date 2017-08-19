/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year, 2 months ago
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        int star = -778477,end = -778477;
        int len = (int)nums.size();
        
        for(int i=0;i<len;i++){
            if(star == -778477 && end == -778477){
                star = end = nums[i];
            }
            else if (star != -1){
                if (nums[i] - end == 1) {
                    end = nums[i];
                }
                else{
                    if(star == end){
                        stringstream stream;
                        stream<<star;
                        ans.push_back(stream.str());
                    }
                    else{
                        stringstream stream;
                        stream<<star<<"->"<<end;
                        ans.push_back(stream.str());
                    }
                    star = end = nums[i];
                }
            }
        }
        
        if(end != -778477){
            if(star == end){
                stringstream stream;
                stream<<star;
                ans.push_back(stream.str());
            }
            else{
                stringstream stream;
                stream<<star<<"->"<<end;
                ans.push_back(stream.str());
            }
        }
        
        return ans;
    }
};
