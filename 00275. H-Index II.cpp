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
 
 
 275. H-Index II
 
 Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 
 
 */


/**
 
 H-index h因子，评价一个学术成就的新方法。 指的是一个至少有n篇论文被引用了n次
 
 82 / 82 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 
 
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        
        int len = (int)citations.size() ;
        
        for(int i=1,last = len - 1; last > -1; --last,++i){
            if(citations[last] < i){
                break;
            }
            ++ans;
        }
        
        return ans;
    }
};


int main(){
    Solution solve;
    vector<int> citations{4,4,4,4,4};
    cout<<solve.hIndex(citations)<<endl;
    return 0;
}

