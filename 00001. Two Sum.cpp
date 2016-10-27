class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        deal(numbers);
        sort(V.begin(),V.end(),cmp);
//        for(int i=0;i<(int)V.size();i++)
//        {
//            cout<<V[i].second<<" : "<<V[i].first<<endl;
//        }
        int s = 0,e = V.size()-1;
        int sum;
        while(s < e)
        {
            sum = V[s].second + V[e].second;
            if(sum > target) e--;
            else if(sum < target) s++;
            else
            {
                s = V[s].first;
                e = V[e].first;
                break;
            }
        }
        ans.push_back(min(s,e));
        ans.push_back(max(s,e));
        return ans;
    }
    void deal(vector<int> &numbers)
    {
        V.clear();
        for(int i=0;i<(int)numbers.size();i++)
            V.push_back(make_pair(i+1,numbers[i]));
    }
    static bool cmp(const pair<int,int>& fir,const pair<int,int>& sec)
    {
        return fir.second < sec.second;
    }
private:
    vector<pair<int,int> > V;
};

