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

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/**
 
 
 638. Shopping Offers
 
 In LeetCode Store, there are some kinds of items to sell. Each item has a price.
 
 However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
 
 You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.
 
 Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.
 
 You could use any of special offers as many times as you want.
 
 Example 1:
 Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
 Output: 14
 Explanation:
 There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
 In special offer 1, you can pay $5 for 3A and 0B
 In special offer 2, you can pay $10 for 1A and 2B.
 You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
 Example 2:
 Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
 Output: 11
 Explanation:
 The price of A is $2, and $3 for B, $4 for C.
 You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
 You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C.
 You cannot add more items, though only $9 for 2A ,2B and 1C.
 
 
 Note:
 There are at most 6 kinds of items, 100 special offers.
 For each item, you need to buy at most 6 of them.
 You are not allowed to buy more items than you want, even if that would lower the overall price.
 
 
 */


/**
 
 因为 数据规模小(共有6种商品，且每种商品最多购买6个). 所以直接暴力dp即可
 
 53 / 53 test cases passed.
 Status: Accepted
 Runtime: 136 ms
 */

const int N(7);
int dp[N][N][N][N][N][N];

class Solution {
public:
    bool isValidOffices(const int count, const vector<int> special, const vector<int> needs){
        
        for(size_t i=0;i<needs.size();i++){
            if(special[i] * count > needs[i]){
                return false;
            }
        }
        
        return true;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        memset(dp, 1, sizeof(int) * N*N*N*N*N*N);
        dp[0][0][0][0][0][0] = 0;
        vector<int> p(N,0);
        vector<int> n(N,0);
        
        for(size_t i = 0; i < needs.size(); ++i){
            p[i] = price[i];
            n[i] = needs[i];
        }
        
        vector<vector<int>> newSpecial;
        for(vector<int> spec : special){
            vector<int> newSpec = spec;
            int price = spec.back();
            if(newSpec.size() < 7){
                newSpec[spec.size() - 1] = 0;
                for(size_t i = newSpec.size() ; i < 6; ++i){
                    newSpec.push_back(0);
                }
                newSpec.push_back(price);
            }
            newSpecial.push_back(newSpec);
        }
        
        
        for(int a=0;a<=n[0];++a){
            dp[a][0][0][0][0][0] = min(dp[a][0][0][0][0][0], dp[0][0][0][0][0][0] + a * p[0]);
            for(int b=0;b<=n[1];++b){
                dp[a][b][0][0][0][0] = min(dp[a][b][0][0][0][0], dp[a][0][0][0][0][0] + b * p[1]);
                for(int c=0;c<=n[2];++c){
                    dp[a][b][c][0][0][0] = min(dp[a][b][c][0][0][0], dp[a][b][0][0][0][0] + c * p[2]);
                    for(int d=0;d<=n[3];++d){
                        dp[a][b][c][d][0][0] = min(dp[a][b][c][d][0][0], dp[a][b][c][0][0][0] + d * p[3]);
                        for(int e=0;e<=n[4];++e){
                            dp[a][b][c][d][e][0] = min(dp[a][b][c][d][e][0], dp[a][b][c][d][0][0] + e * p[4]);
                            for(int f=0;f<=n[5];++f){
                                dp[a][b][c][d][e][f] = min(dp[a][b][c][d][e][f], dp[a][b][c][d][e][0] + f * p[5]);
                            }
                        }
                    }
                }
            }
        }
        
        
        for(vector<int> spec : newSpecial){
            
            for(int a = spec[0]; a<7;++a){
                for(int b = spec[1]; b<7;++b){
                    for(int c = spec[2];c<7;++c){
                        for(int d = spec[3];d<7;++d){
                            for(int e = spec[4];e<7;++e){
                                for(int f = spec[5];f<7;++f){
                                    dp[a][b][c][d][e][f] = min(dp[a][b][c][d][e][f], dp[a - spec[0]][b - spec[1]][c - spec[2]][d - spec[3]][e - spec[4]][f - spec[5]] + spec[6]);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
        return dp[n[0]][n[1]][n[2]][n[3]][n[4]][n[5]];
    }
};

// [2,5], [[3,0,5],[1,2,10]], [3,2] => 14
// [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1] => 11
// [2,3],[[1,0,1],[0,1,2]],[1,1] => 3

/* [9,6,1,5,3,4]
 [[1,2,2,1,0,4,14],[6,3,4,0,0,1,16],[4,5,6,6,2,4,26],[1,1,4,3,4,3,15],[4,2,5,4,4,5,15],[4,0,0,2,3,5,13],[2,4,6,4,3,5,7],[3,3,4,2,2,6,21],[0,3,0,2,3,3,15],[0,2,4,2,2,5,24],[4,1,5,4,5,4,25],[6,0,5,0,1,1,14],[4,0,5,2,1,5,8],[4,1,4,4,3,1,10],[4,4,2,1,5,0,14],[2,4,4,1,3,1,16],[4,2,3,1,2,1,26],[2,4,1,6,5,3,2],[0,2,0,4,0,0,19],[3,1,6,3,3,1,23],[6,2,3,2,4,4,16],[5,3,5,5,0,4,5],[5,0,4,3,0,2,20],[5,3,1,2,2,5,8],[3,0,6,1,0,2,10],[5,6,6,1,0,4,12],[0,6,6,4,6,4,21],[0,4,6,5,0,0,22],[0,4,2,4,4,6,16],[4,2,1,0,6,5,14],[0,1,3,5,0,3,8],[5,5,3,3,2,0,4],[1,0,3,6,2,3,18],[4,2,6,2,2,5,2],[0,2,5,5,3,6,12],[1,0,6,6,5,0,10],[6,0,0,5,5,1,24],[1,4,6,5,6,3,19],[2,2,4,2,4,2,20],[5,6,1,4,0,5,3],[3,3,2,2,1,0,14],[0,1,3,6,5,0,9],[5,3,6,5,3,3,11],[5,3,3,1,0,2,26],[0,1,1,4,2,1,16],[4,2,3,2,1,4,6],[0,2,1,3,3,5,15],[5,6,4,1,2,5,18],[1,0,0,1,6,1,16],[2,0,6,6,2,2,17],[4,4,0,2,4,6,12],[0,5,2,5,4,6,6],[5,2,1,6,2,1,24],[2,0,2,2,0,1,14],[1,1,0,5,3,5,16],[0,2,3,5,5,5,6],[3,2,0,6,4,6,8],[4,0,1,4,5,1,6],[5,0,5,6,6,3,7],[2,6,0,0,2,1,25],[0,4,6,1,4,4,6],[6,3,1,4,1,1,24],[6,2,1,2,1,4,4],[0,1,2,3,0,1,3],[0,2,5,6,5,2,13],[2,6,4,2,2,3,17],[3,4,5,0,5,4,20],[6,2,3,4,1,3,4],[6,4,0,0,0,5,16],[3,1,2,5,0,6,11],[1,3,2,2,5,6,14],[1,3,4,5,3,5,18],[2,1,1,2,6,1,1],[4,0,4,0,6,6,8],[4,6,0,5,0,2,1],[3,1,0,5,3,2,26],[4,0,4,0,6,6,6],[5,0,0,0,0,4,26],[4,3,2,2,0,2,14],[5,2,4,0,2,2,26],[3,4,6,0,2,4,25],[2,1,5,5,1,3,26],[0,5,2,4,0,2,24],[5,2,5,4,5,0,1],[5,3,0,1,5,4,15],[6,1,5,1,2,1,21],[2,5,1,2,1,4,15],[1,4,4,0,0,0,1],[5,0,6,1,1,4,22],[0,1,1,6,1,4,1],[1,6,0,3,2,2,17],[3,4,3,3,1,5,17],[1,5,5,4,5,2,27],[0,6,5,5,0,0,26],[1,4,0,3,1,0,13],[1,0,3,5,2,4,5],[2,2,2,3,0,0,11],[3,2,2,1,1,1,6],[6,6,1,1,1,6,26],[1,5,1,2,5,2,12]]
 [6,6,6,1,6,6] => 34
 */

// [4,3,2,9,8,8]
// [[1,5,5,1,4,0,18],[3,3,6,6,4,2,32]]
// [6,5,5,6,4,1] => 91

int main(){
    
    Solution solve;
    vector<int> price({2,3});
    vector<int> needs({1,1});
    vector<vector<int>> special;
    
    
    vector<int> offer1({1,0,1});
    vector<int> offer2({0,1,2});
    special.push_back(offer1);
    special.push_back(offer2);
    
    cout<<solve.shoppingOffers(price, special, needs)<<endl;
    
    return 0;
}

