
//Accepted	28 ms	cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ans = 0;
        height.push_back(0);
        int n = (int)height.size();
        stack<int> s;
        int ranger = 0;
        while(ranger < n){
            if(s.empty() || height[ranger] >= height[s.top()]) s.push(ranger++);
            else{
                int index = s.top();
                s.pop();
                ans = max(ans, height[index] * (s.empty() ? ranger : ranger - s.top() - 1));
            }
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        size_t n = matrix.size(),m = matrix[0].size();
        vector<int> heights(m,0);
        // init
        for(int i=0;i<m;i++){
            if(matrix[0][i] == '1') heights[i] = 1;
        }
        
        int ans = largestRectangleArea(heights);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1') heights[j]+=1;
                else heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        
        return ans;
    }
    
private:
    int max(const int a,const int b){
        return a > b ? a : b;
    }
};

