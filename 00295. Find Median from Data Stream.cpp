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
 
 295. Find Median from Data Stream
 
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 
 Examples:
 [2,3,4] , the median is 3
 
 [2,3], the median is (2 + 3) / 2 = 2.5
 
 Design a data structure that supports the following two operations:
 
 void addNum(int num) - Add a integer number from the data stream to the data structure.
 double findMedian() - Return the median of all elements so far.
 For example:
 
 addNum(1)
 addNum(2)
 findMedian() -> 1.5
 addNum(3)
 findMedian() -> 2
 
 */


/**
 
 Heap/Design
 
 18 / 18 test cases passed.
 Status: Accepted
 Runtime: 228 ms
 
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        nums.clear();
    }
    
    void addNum(int num) {
        vector<int>::iterator iter = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(iter, num);
    }
    
    double findMedian() {
        double ans = 0;
        
        if(nums.size() & 0x01){
            ans = nums[nums.size()>>1];
        } else if(nums.size() > 1){
            ans = (nums[nums.size()>>1] + nums[(nums.size()>>1) - 1])*1.0/2;
        }
        
        return ans;
    }
    
private:
    vector<int> nums;
};


int main(){
    
    
    return 0;
}
