
//Accepted	48 ms	cpp
class Solution {
public:
    int trap(int A[], int n) {
        int *leftMax = (int*)calloc(n+1,4);
        
        int *rightMax = (int*)calloc(n+1,4);

        
//        output(leftMax, rightMax, n);
        int last = n-1;
        leftMax[0] = A[0];
        rightMax[last] = A[last];
        for(int i=1;i<n;i++)
        {
            leftMax[i] = max(leftMax[i-1],A[i]);
            rightMax[last-i] = max(rightMax[last-i+1],A[last-i]);
        }
        
//        output(leftMax,rightMax,n);
        int ans = 0;
        for(int i=1;i<last;i++)
        {
            int tmp = min(leftMax[i-1],rightMax[i+1]);
            if(tmp > A[i])
                ans += (tmp - A[i]);
        }
        return ans;
    }
    
    void output(int *leftMax,int *rightMax,int n)
    {
        printf("this is leftMax:\n");
        for(int i=0;i<n;i++)
            printf("%d ",leftMax[i]);
        printf("\n");
        
        printf("this is rightmax:\n");
        for(int i=0;i<n;i++)
            printf("%d ",rightMax[i]);
        printf("\n");
    }
};
