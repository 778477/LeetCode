
//Accepted	68 ms	cpp
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        int p = 0 , q = n-1;
        int mid;
        while(p <= q)
        {
            mid = ((q-p)>>1)+p;
            if(A[mid] < target) p = mid+1;
            else if(A[mid] > target) q = mid-1;
            else break;
        }

        if(A[mid]!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        p = mid;
        while(p > 0 && A[p-1] == target) p--;
        q = mid;
        while(q < n-1 && A[q+1] == target) q++;
        ans.push_back(p);
        ans.push_back(q);
        return ans;
    }
};
