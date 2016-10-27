
//Accepted	4 ms	cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
//            cout<<endl;
//            output(matrix);
        }
        
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    
    
    void output(vector<vector<int>>& nums){
        for_each(nums.begin(), nums.end(), [&](const vector<int> &items){
            for_each(items.begin(), items.end(), [&](const int &item){
                cout<<item<<" ";
            });
            cout<<endl;
        });
    }
};
