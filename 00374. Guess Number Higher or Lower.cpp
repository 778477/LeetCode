/*
[Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)

裸二分

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
 */


int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1,right = n;
        int mid = left + ((right-left)>>1);
        int ans = guess(mid);
        
        while(ans){
            if(ans > 0){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
            mid = ((right-left)>>1)+left;
            ans = guess(mid);
        }
        
        return mid;
    }
};
