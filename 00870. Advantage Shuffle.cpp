//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 870. Advantage Shuffle
 
 Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
 
 Return any permutation of A that maximizes its advantage with respect to B.
 
 
 
 Example 1:
 
 Input: A = [2,7,11,15], B = [1,10,4,11]
 Output: [2,11,7,15]
 Example 2:
 
 Input: A = [12,24,8,32], B = [13,25,32,11]
 Output: [24,32,8,12]
 
 
 Note:
 
 1 <= A.length = B.length <= 10000
 0 <= A[i] <= 10^9
 0 <= B[i] <= 10^9
 
 */

/**
 
 
 67 / 67 test cases passed.
 Status: Accepted
 Runtime: 112 ms
 
 小心 upper_bound 在 erase之后可能会野指针，每次查找到末尾的时候重置成begin()
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();


class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        
        sort(A.begin(), A.end());
        for(int num : B){
            auto idx = upper_bound(A.begin(), A.end(), num);
            if(idx == A.end()){
                idx = A.begin();
            }
            ans.push_back(*idx);
            A.erase(idx);
        }
        
        return ans;
    }
};


int main(){
    
    
    Solution solve;
    vector<int> A{2,7,11,15};
    vector<int> B{1,10,4,11};
    
    vector<int> ans = solve.advantageCount(A, B);
    
    for(int num : ans){
        cout<<num<<",";
    }
    cout<<endl;
    
    return 0;
}
