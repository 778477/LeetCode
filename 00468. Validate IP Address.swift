//
//  main.swift
//  LeetCodeWithSwift
//
//  Created by miaoyou.gmy on 2016/12/26.
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

import Foundation

/*
 468. Validate IP Address
 Total Accepted: 1359
 Total Submissions: 6227
 Difficulty: Medium
 Contributors: Cyber233
 In this problem, your job to write a function to check whether a input string is a valid IPv4 address or IPv6 address or neither.
 
 IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
 
 Besides, you need to keep in mind that leading zeros in the IPv4 is illegal. For example, the address 172.16.254.01 is illegal.
 
 IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a legal one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
 
 However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
 
 Besides, you need to keep in mind that extra leading zeros in the IPv6 is also illegal. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is also illegal.
 
 Note: You could assume there is no extra space in the test cases and there may some special characters in the input string.
 
 Example 1:
 Input: "172.16.254.1"
 
 Output: "IPv4"
 
 Explanation: This is a valid IPv4 address, return "IPv4".
 Example 2:
 Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
 
 Output: "IPv6"
 
 Explanation: This is a valid IPv6 address, return "IPv6".
 Example 3:
 Input: "256.256.256.256"
 
 Output: "Neither"
 
 Explanation: This is neither a IPv4 address nor a IPv6 address.
 
 **/

/*
 
 102 / 102 test cases passed.
 Status: Accepted
 Runtime: 46 ms
 Submitted: 0 minutes ago
 
 **/


class Solution {
    func validIPAddress(_ IP: String) -> String {
        
        if(isIPv4(IP)){
            return "IPv4"
        } else if(isIPv6(IP)){
            return "IPv6"
        } else{
            return "Neither"
        }
        
    }
    
    private func isIPv4(_ IP: String) -> Bool {
        let items = IP.components(separatedBy: ".")
        
        if(items.count != 4) { return false }
        
        for item in items {
            var tmp = 0
            if(item.characters.count > 3 || item.characters.count < 1){
                return false
            }
            
            for char in item.characters{
                if(char < "0" || char > "9"){
                    return false
                }
                
                tmp = tmp * 10 + Int(String(char))!
            }
            
            if(tmp < 0 || tmp > 255){
                return false
            }
            
            if((tmp > 0 && item.characters.first == "0") || (tmp == 0 && item.characters.count > 1)){
                return false
            }
        }
        
        
        return true
    }
    
    private func isIPv6(_ IP: String) -> Bool {
        let items = IP.components(separatedBy: ":")
        if(items.count != 8){
            return false
        }
        
        for item in items{
            if(item.characters.count > 4 || item.characters.count < 1){
                return false;
            }
            
            for char in item.lowercased().characters{
                if((char < "0" || char > "9") && (char < "a" || char > "f")){
                    return false
                }
            }
        }
        
        
        
        return true
    }
}

let solve = Solution()

print(solve.validIPAddress("2001:db8:85a3:0::8a2E:0370:7334"))

