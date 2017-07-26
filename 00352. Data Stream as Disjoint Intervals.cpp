
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
 
 
 352. Data Stream as Disjoint Intervals
 
 Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
 
 For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
 
 [1, 1]
 [1, 1], [3, 3]
 [1, 1], [3, 3], [7, 7]
 [1, 3], [7, 7]
 [1, 3], [6, 7]
 Follow up:
 What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
 
 Credits:
 Special thanks to @yunhong for adding this problem and creating most of the test cases.
 
 
 */


/**
 
 纯模拟，维护一个有序数组 二分查找插入元素的下标
 
 9 / 9 test cases passed.
 Status: Accepted
 Runtime: 115 ms
 
 **/


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        lowers.clear();
        ans.clear();
    }
    
    void addNum(int val) {
        vector<int>::iterator iter = lower_bound(lowers.begin(), lowers.end(), val);
        unsigned long idx = iter - lowers.begin();
        
        if(ans.empty()){
            lowers.push_back(val);
            ans.push_back(Interval(val, val));
        } else if(idx == ans.size()){
            Interval last = ans.back();
            if(val > last.end + 1){
                lowers.push_back(val);
                ans.push_back(Interval(val, val));
            } else if(val == last.end + 1){
                ans.pop_back();
                ans.push_back(Interval(last.start, last.end + 1));
            }
        } else {
            if(idx == 0){
                if(val == ans[0].start - 1){
                    ans[0].start = val;
                    lowers[0] = val;
                } else if(val < ans[0].start - 1){
                    ans.insert(ans.begin(), Interval(val, val));
                    lowers.insert(lowers.begin(), val);
                }
            } else{
                Interval &cur = ans[idx];
                Interval &bef = ans[idx - 1];
                
                if(bef.end + 1 == val && cur.start - 1 == val){
                    bef.end = cur.end;
                    ans.erase(ans.begin() + idx);
                    lowers.erase(iter);
                } else if(bef.end + 1 == val){
                    bef.end = val;
                } else if(cur.start - 1 == val){
                    cur.start = val;
                    lowers[idx] = val;
                } else if(val > bef.end && val < cur.start){
                    ans.insert(ans.begin() + idx, Interval(val, val));
                    lowers.insert(lowers.begin() + idx, val);
                }
            }
        }
        
    }
    
    vector<Interval> getIntervals() {
        return ans;
    }
    
    void output(){
        vector<Interval> param_2 = this->getIntervals();
        
        for(Interval inter: param_2){
            cout<<inter.start<<","<<inter.end<<endl;
        }
        
        cout<<"-----"<<endl;
    }
private:
    vector<int> lowers;
    vector<Interval> ans;
};


/**
 
 ["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]
 [[],[6],[],[6],[],[0],[],[4],[],[8],[],[7],[],[6],[],[4],[],[7],[],[5],[]]
 
 */

/**
 
 [null,null,[[6,6]],null,[[6,6],[6,6]],null,[[0,0],[6,6],[6,6]],null,[[4,4],[0,0],[6,6],[6,6]],null,[[4,4],[0,0],[6,6],[6,6],[8,8]],null,[[4,4],[0,0],[6,6],[6,8]],null,[[6,6],[4,4],[0,0],[6,6],[6,8]],null,[[4,4],[6,6],[4,4],[0,0],[6,6],[6,8]],null,[[4,4],[6,6],[4,4],[0,0],[6,6],[6,8]],null,[[4,4],[6,6],[4,4],[0,0],[5,6],[6,8]]]
 
 [null,null,[[6,6]],null,[[6,6]],null,[[0,0],[6,6]],null,[[0,0],[4,4],[6,6]],null,[[0,0],[4,4],[6,6],[8,8]],null,[[0,0],[4,4],[6,8]],null,[[0,0],[4,4],[6,8]],null,[[0,0],[4,4],[6,8]],null,[[0,0],[4,4],[6,8]],null,[[0,0],[4,8]]]
 
 */



int main(){
    
    
    SummaryRanges *obj = new SummaryRanges();
    // 6,6,0,4,8,7,6,4,7,5
    obj->addNum(6);
    obj->output();
    
    obj->addNum(6);
    obj->output();
    
    obj->addNum(0);
    obj->output();
    
    obj->addNum(4);
    obj->output();
    obj->addNum(8);
    obj->output();
    obj->addNum(7);
    obj->output();
    obj->addNum(6);
    obj->output();
    obj->addNum(4);
    obj->output();
    obj->addNum(7);
    obj->output();
    obj->addNum(5);
    obj->output();
    
    
}


