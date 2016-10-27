
//Accepted	24 ms	cpp
class Solution {
public:
    int jump(int A[], int n) {
        if(n == 1) return 0;

        int steps = 1;
        int oldReach = 0 + A[0], newReach = 0;

        for(int i=1;i<n;i++)
        {
            if(oldReach >= n-1) break;

            if( i <= oldReach) newReach = max(newReach,A[i]+i);
            else
            {
                if(oldReach >= newReach) return -1;
                oldReach = newReach , steps++,i--;
            }
        }
        return steps;
    }
};

