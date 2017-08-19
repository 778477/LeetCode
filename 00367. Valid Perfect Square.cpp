/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year ago
*/
int mySqrt(int x) {
    
    
    float f = x;
    int valInt = *(int *)&f;
    valInt = (1 << 29) + (valInt >> 1) - (1 << 2)  + 2; // guess the star number
    f = *(float *)&valInt;
    
    double val = f;
    val = 0.5*val + 0.5*x / val;
    val = 0.5*val + 0.5*x / val;
    val = 0.5*val + 0.5*x / val;
    val = 0.5*val + 0.5*x / val;
    
    return val;
}


bool isPerfectSquare(int num) {
    int tmp = mySqrt(num);
    
    return tmp*tmp == num;
}
