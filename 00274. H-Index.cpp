//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;



/**
 
 
 274. H-Index
 
 Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
 
 According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
 
 For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
 
 Note: If there are several possible values for h, the maximum one is taken as the h-index.
 
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 
 */


/**
 
 H-index h因子，评价一个学术成就的新方法。 指的是一个至少有n篇论文被引用了n次
 
 81 / 81 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end(),greater<int>());
        
        for(unsigned i = 0; i<citations.size(); ++i){
            if(i+1 > citations[i]){
                break;
            }
            
            ++ans;
        }
        
        return ans;
    }
};


int main(){
    
    
    return 0;
}

