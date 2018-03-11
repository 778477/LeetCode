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

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 799. Champagne Tower
 
 We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup (250ml) of champagne.
 
 Then, some champagne is poured in the first glass at the top.  When the top most glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has it's excess champagne fall on the floor.)
 
 For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.
 
 
 
 Now after pouring some non-negative integer cups of champagne, return how full the j-th glass in the i-th row is (both i and j are 0 indexed.)
 
 
 
 Example 1:
 Input: poured = 1, query_glass = 1, query_row = 1
 Output: 0.0
 Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.
 
 Example 2:
 Input: poured = 2, query_glass = 1, query_row = 1
 Output: 0.5
 Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
 
 
 
 */


/**
 
 309 / 309 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 
 */


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double tower[101][101] = {0.0};
        
        tower[0][0] = poured;
        for(int i = 0;i<100;++i){
            for(int j=0;j<=i;++j){
                if(tower[i][j] > 1){
                    
                    tower[i+1][j] += (tower[i][j] - 1)*1.0/2;
                    tower[i+1][j+1] += (tower[i][j] - 1)*1.0/2;
                    
                    tower[i][j] = 1.0;
                }
            }
        }
        
        
        return tower[query_row][query_glass];
    }
};

int main(){
    
    
    Solution solve;
    
    cout<<solve.champagneTower(6, 3, 1)<<endl;
    
    return 0;
}
