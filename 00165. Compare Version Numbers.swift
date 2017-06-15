//
//  main.swift
//  LeetCodeWithSwift
//
//  Created by miaoyou.gmy on 2016/12/26.
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

import Foundation

/**
 
 165. Compare Version Numbers
 
 Compare two version numbers version1 and version2.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 
 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 
 Here is an example of version numbers ordering:
 
 0.1 < 1.1 < 1.2 < 13.37
 
 */


/*
 71 / 71 test cases passed.
 Status: Accepted
 Runtime: 52 ms
 */

class Solution {
    func compareVersion(_ version1: String, _ version2: String) -> Int {
        var Arr1 = version1.components(separatedBy: ".");
        var Arr2 = version2.components(separatedBy: ".");
        
        let maxCount = Arr1.count > Arr2.count ? Arr1.count : Arr2.count;
        let count1 = Arr1.count,count2 = Arr2.count;
        
        for _ in count1...maxCount{
            Arr1.append("0")
        }
        
        for _ in count2...maxCount{
            Arr2.append("0")
        }
        
        
        
        for i in 0...Arr1.count-1{
            if(Int(Arr1[i])! > Int(Arr2[i])!){
                return 1;
            } else if(Int(Arr1[i])! < Int(Arr2[i])!){
                return -1;
            }
        }
        return 0;
    }
}


let solve = Solution()

print(solve.compareVersion("1.0.0", "2.1.0"))
