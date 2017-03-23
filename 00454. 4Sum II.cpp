//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 454. 4Sum II
 
 Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 
 To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
 
 Example:
 
 Input:
 A = [ 1, 2]
 B = [-2,-1]
 C = [-1, 2]
 D = [ 0, 2]
 
 Output:
 2
 
 Explanation:
 The two tuples are:
 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 Subscribe to see which companies asked this question.
 
 
 */


/**
 
 Binary Search / Hash Table
 
 分别统计出 A,B 和 C,D 的和，然后二分查找
 
 48 / 48 test cases passed.
 Status: Accepted
 Runtime: 552 ms
 
 */


class Solution {
public:
    void deal(vector<int>& A,vector<int>& B,vector<int>& AB,unordered_map<int, unsigned>& table){
        for( int a : A ){
            for ( int b : B ){
                if(!table[a+b]){
                    AB.push_back(a+b);
                    table[a+b] = 1;
                } else {
                    ++table[a+b];
                }
            }
        }
    }
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unsigned ans = 0;
        vector<int> AB,CD;
        unordered_map<int, unsigned> abTable,cdTable; // sum : count
        deal(A, B, AB, abTable);
        deal(C, D, CD, cdTable);
        
        sort(CD.begin(), CD.end(), [](const int a,const int b){
            return a < b;
        });
        
        for( int ab : AB ){
            if(binary_search(CD.begin(), CD.end(), (0-ab))){
                ans += abTable[ab] * cdTable[(0-ab)];
            }
        }
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> a({1,2});
    vector<int> b({-2,-1});
    vector<int> c({-1,2});
    vector<int> d({0,2});
    
    
    cout<<solve.fourSumCount(a, b, c, d)<<endl;
    
    
    return 0;
}
