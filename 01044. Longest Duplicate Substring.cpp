//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
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
#include <unordered_set>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;

/**
 1044. Longest Duplicate Substring
 
 Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
 
 Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)
 
 
 
 Example 1:
 
 Input: "banana"
 Output: "ana"
 Example 2:
 
 Input: "abcd"
 Output: ""
 
 
 Note:
 
 2 <= S.length <= 10^5
 S consists of lowercase English letters.
 
 */

/**
 
 16 / 16 test cases passed.
 Status: Accepted
 Runtime: 1484 ms
 Memory Usage: 396.5 MB
 
 
 basic idea
     Rabin-Karp substring search + binary search
 
 
 https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
 
 */


class Solution {
public:
    typedef long long LL;
    LL hashVal[100001];
    const int P = 256;
    const int MOD = 1e9+7;
    int n;
    string ans, str;
    
    bool isSame(int x, int y, int len){
        for(int i=0;i<len;++i){
            if(str[x + i] != str[y + i]) return false;
        }
        return true;
    }
    
    bool RabinKarpSearch(int len){
        
        hashVal[0] = 0;
        LL pow = 1;
        // rolling hash
        for(int i=0;i<len;++i){
            hashVal[0] = (hashVal[0] * P + str[i]) % MOD;
            if(i != 0) pow = (pow * P) % MOD;
        }
        
        for(int i=1;i<= n - len; ++i){
            hashVal[i] = ((hashVal[i-1] - str[i-1]*pow) % MOD + MOD) % MOD;
            hashVal[i] = (hashVal[i] * P + str[i + len - 1]) % MOD;
        }
        
        unordered_map<LL, vector<int>> mp;
        
        for(int i=0; i<= n - len; ++i){
            if(mp.find(hashVal[i]) != mp.end()){
                for(int other : mp[hashVal[i]]){
                    if(isSame(i, other, len)){
                        if(len > ans.length()){
                            ans = str.substr(i,len);
                        }
                        return true;
                    }
                }
            }
            mp[hashVal[i]].push_back(i);
        }
        
        return false;
    }
    
    string longestDupSubstring(string S) {
        n = (int)S.length();
        str = S;
        ans = "";
        
        int low = 0, high = n, len;
        while(low <= high){
            len = (high + low)>>1;
            
            if(len < ans.length()){
                low = len + 1;
                continue;
            }
            
            if(RabinKarpSearch(len)){
                low = len + 1;
            } else {
                high = len - 1;
            }
        }
        
        return this->ans;
    }
};


int main(){
    Solution solve;
    cout<<solve.longestDupSubstring("moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc")<<endl;
    return 0;
}

