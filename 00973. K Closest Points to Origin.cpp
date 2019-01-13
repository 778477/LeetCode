class Solution {
public:
    int dis(vector<int> p){
        return p[0]*p[0] + p[1]*p[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [&](const vector<int>& a, vector<int>& b){
            return dis(a) < dis(b);
        });
        
        
        vector<vector<int>> ans;
        for(int i=0;i<K;++i){
            ans.push_back(points[i]);
        }
        return ans;
    }
};
