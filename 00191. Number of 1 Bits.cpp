


/**
 
 Status: Accepted
 Runtime: 4 ms
 Submitted: 1 year, 3 months ago
 
 */

int hammingWeight(uint32_t n) {
    int cnt=0;
    while(n){
        cnt+=(n&0x01);
        n>>=1;
    }
    return cnt;
}
