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
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 767. Reorganize String
 
 Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
 
 If possible, output any possible result.  If not possible, return the empty string.
 
 Example 1:
 
 Input: S = "aab"
 Output: "aba"
 Example 2:
 
 Input: S = "aaab"
 Output: ""
 Note:
 
 S will consist of lowercase letters and have length in range [1, 500].
 
 
 
 
 */


/**
 
 抽屉原理
 
 
 62 / 62 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */



class Solution {
public:
    string reorganizeString(string S) {
        string ans = "";
        
        vector<int> bucket(26,0);
        int max = 0;
        
        for(char ch : S){
            ++bucket[ch - 'a'];
            max = max > bucket[ch - 'a'] ? max : bucket[ch -'a'];
        }
        
        if(max > (S.length() + 1)/2) return ans;
        
        typedef pair<char, int> CountValue;
        vector<CountValue> ps; // index : count
        
        for(int i=0;i<26;++i){
            if(bucket[i] > 0){
                ps.push_back(make_pair(i + 'a', bucket[i]));
            }
        }
        
        sort(ps.begin(), ps.end(), [](const CountValue a,const CountValue b){
            return a.second > b.second;
        });
        
        
        string sortStr = "";
        
        for(CountValue c : ps){
            sortStr += string(c.second,c.first);
        }
        
        for(int i=0,j=((int)S.length()-1)/2 + 1; i<=((int)S.length()-1)/2; ++i,++j){
            ans += sortStr[i];
            if(j < S.length()) ans += sortStr[j];
        }
        
        
        return ans;
    }
};


/**
 
 Test Case 61/62 Time Limit Exceeded
 tndsewnllhrtwsvxenkscbivijfqnysamckzoyfnapuotmdexzkkrpmppttficzerdndssuveompqkemtbwbodrhwsfpbmkafpwyedpcowruntvymxtyyejqtajkcjakghtdwmuygecjncxzcxezgecrxonnszmqmecgvqqkdagvaaucewelchsmebikscciegzoiamovdojrmmwgbxeygibxxltemfgpogjkhobmhwquizuwvhfaiavsxhiknysdghcawcrphaykyashchyomklvghkyabxatmrkmrfsppfhgrwywtlxebgzmevefcqquvhvgounldxkdzndwybxhtycmlybhaaqvodntsvfhwcuhvuccwcsxelafyzushjhfyklvghpfvknprfouevsxmcuhiiiewcluehpmzrjzffnrptwbuhnyahrbzqvirvmffbxvrmynfcnupnukayjghpusewdwrbkhvjnveuiionefmnfxao
 
 Answer:
 eweweweweweweweweweweweweweueueueueueueueueueueueueueueuhuhuhuhuhuhshshshshshshshshshshshshshshshshshshshphphphpcpcpcpcpcpcpcpcpcpcpcpcpcpcpcrcrcrcrcrcrcrcrcrcrcrcrmrmrmrmrmrmrmxmxmxmxmxmxmxmxmxmxmxmxmxmxmxmxmxmxmgmgvgvgvgvgvgvgvgvgvgvgvgvgvgvgvgvovovovovovovovovonononononononononbnbnbnbnbnbnbnbnbnbnbnbnbnbnbabaiaiaiaiaiaiaiaiaiaiaiaiaiaiaiaiatatatatatftftftftftftftftftftftfdfdfdfdfdfdfdfdfdfdfdydydydydyzyzyzyzyzyzyzyzyzyzyzyzyzyzyjyjyjyjkjkjkjkjkjkjkjklklklklklklklklklklklkqkqkqwqwqwqwqwqwqwqwq
 
 */

int main(){
    
    Solution solve;
    cout<<solve.reorganizeString("aaab")<<endl;
    
    
    return 0;
}
