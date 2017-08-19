/**
 Status: Accepted
 Runtime: 4 ms
 Submitted: 1 year, 3 months ago
*/
bool isUgly(int num) {
    
    if(!num) return false;
    
    while(!(num%2)) num/=2;
    
    while(!(num%3)) num/=3;
    
    while(!(num%5)) num/=5;
    
    
    return num == 1;
}
