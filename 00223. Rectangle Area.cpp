/**
 Status: Accepted
 Runtime: 24 ms
 Submitted: 2 years, 2 months ago
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A)*(D-B) + (G-E)*(H-F);
        return area - judge(A,C,E,G) * judge(B,D,F,H);
    }
    
    int judge(int x1,int x2,int x3,int x4){
        if(x3 >= x2) return 0;
        if(x1 >= x4) return 0;
        return min(x2,x4) - max(x1,x3);
    }
};
