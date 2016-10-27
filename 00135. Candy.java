
//Accepted	376 ms	java
public class Solution {
    public int candy(int[] ratings) {
        int ans = 0;
        
        if(ratings.length == 1) return 1;
        
        int []num = new int[ratings.length];
        int len = ratings.length;
        int candy = 1;
        for(int i=1;i<len;i++)
        {
        	if(ratings[i] > ratings[i-1])
        		num[i] = Math.max(candy++,num[i]);
        	else
        		candy = 1;
        }
        
        candy = 1;
        for(int i = len-2;i>-1;i--)
        {
        	if(ratings[i] > ratings[i+1])
        		num[i] = Math.max(candy++,num[i]);
        	else
        		candy = 1;
        }
        
        for(int i=0;i<len;i++)
        	ans+=num[i];
        
        return ans+len;
    }
}
