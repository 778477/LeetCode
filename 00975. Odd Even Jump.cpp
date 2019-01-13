

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        vector<bool> odd = vector<bool>(A.size(), false);
        vector<bool> even = vector<bool>(A.size(), false);
        int n = A.size() - 1;
        odd[n] = even[n] = true;
        int ans = 1;
        unordered_map<int,int> mp;
        set<int> st;
        st.insert(A.back());
        mp[A.back()] = n;
        
        for(int i=n-1; i>-1; --i){
            
            // odd
            auto oddIdx = st.lower_bound(A[i]);
            if(oddIdx != st.end() && mp.find(*oddIdx) != mp.end()){
                odd[i] = even[mp[*oddIdx]];
                ans = ans + (odd[i] ? 1 : 0);
            }
            // even
            auto evenIdx = st.lower_bound(A[i]);
            if(*evenIdx != A[i] && evenIdx != st.begin()){
                evenIdx = prev(evenIdx);
            }
            if(*evenIdx <= A[i] && mp.find(*evenIdx) != mp.end()){
                even[i] = odd[mp[*evenIdx]];
            }
            
            if(st.find(A[i]) == st.end()){
                st.insert(A[i]);
            }
            mp[A[i]] = i;
        }
        
        //        for(int i=0;i<=n;++i){
        //            cout<<i<<","<<odd[i]<<","<<even[i]<<endl;
        //        }
        
        
        return ans;
    }
};
