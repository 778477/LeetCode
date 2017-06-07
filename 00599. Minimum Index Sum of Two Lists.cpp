//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
 
 
 599. Minimum Index Sum of Two Lists
 
 
 Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
 
 You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
 
 Example 1:
 Input:
 ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
 Output: ["Shogun"]
 Explanation: The only restaurant they both like is "Shogun".
 Example 2:
 Input:
 ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 ["KFC", "Shogun", "Burger King"]
 Output: ["Shogun"]
 Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
 Note:
 The length of both lists will be in the range of [1, 1000].
 The length of strings in both lists will be in the range of [1, 30].
 The index is starting from 0 to the list length minus 1.
 No duplicates in both lists.
 
 
 */

/*
 
 133 / 133 test cases passed.
 Status: Accepted
 Runtime: 188 ms
 
 */




class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        
        size_t limit = list1.size() + list2.size();
        
        for (size_t i = 0; i < list1.size(); i++){
            for (size_t j = 0; j < list2.size(); j++){
                if(list1[i] == list2[j]){
                    limit = min(limit, i+j);
                }
            }
        }
        
        for (size_t i = 0; i < list1.size(); i++){
            for (size_t j = 0; j < list2.size(); j++){
                if(list1[i] == list2[j] && i+j == limit){
                    ans.push_back(list1[i]);
                }
            }
        }
        
        return ans;
    }
};


int main(){
    
    Solution solve;
    vector<string> list1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    
    vector<string> ans = solve.findRestaurant(list1, list2);
    
    for (string restaurant : ans){
        cout<<restaurant<<endl;
    }
    
    return 0;
}
