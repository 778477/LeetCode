/*
[Perfect Squares](https://leetcode.com/problems/perfect-squares/)


# 题目大意
给定一个正整数n，找出最少个数 平方数之和等于n。

examle：

`n=12` `12 = 4 + 4 + 4` return 3 

`n=13`  `13 = 4 + 9` return 2


# 思考
我一开始以为是数学题。猜想是否有什么方便快速的方式？最后看了一下题目标签`Breadth-first Search`。嗯！计上心头：） 注意我下面的剪枝策略，直接搜索的话是会超时的。

我第两次提交的时候，遇到`9975`这个Test Case就超时了。然后剪枝优化之后 `104ms Accepted`

*/




class Solution {
public:
    int numSquares(int n) {
        int ans = 0;
        ans = bfs(n);
        return ans;
    }
    
    int bfs(int n){
        queue<State> Q;
        Q.push(State(n));
        vector<int> V(n,0xfff3fff); 
        
        while(!Q.empty()){
            State s = Q.front();
            Q.pop();
            
            if(!s.num) return s.step;
            
            int starIdx = sqrt(s.num);
            for(int i = starIdx; i>0;i--){
                int tmp = s.num - i*i;
                if(V[tmp] > s.step + 1){
                    Q.push(State(s.num - i*i,s.step+1));
                    V[tmp] = s.step + 1;
                }
            }
            
        }
        
        return 0;
    }
    
private:
    class State{
    public:
        int num,step;
        State(int _n=0,int _s=0){
            num = _n;
            step =_s;
        }
    };
    
};




