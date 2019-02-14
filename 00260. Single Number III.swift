/**
 260. Single Number III
 DescriptionHintsSubmissionsDiscussSolution
 Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 
 Example:
 
 Input:  [1,2,1,3,2,5]
 Output: [3,5]
 Note:
 
 The order of the result is not important. So in the above example, [5, 3] is also correct.
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 
 
 30 / 30 test cases passed.
 Status: Accepted
 Runtime: 76 ms
 Memory Usage: 18.8 MB
 */


/*
 解题思路： 比较经典的一道题，之前在辽宁省赛的时候遇到过。暴力解法有排序或者哈希
 但如果数据规模大的话，暴力解法是会被卡死的。
 这里考察的用意还是位运算，注意分治思想：
 先遍历异或一次 得到tmp。
 这里的tmp是两个出现奇数次的数值异或结果，根据异或的性质：相同位得0 不同位得1
 即我们可以按照 第一个出1的位将原数组划分成两个数组，使两个出现奇数次的数值分开。
 这样题目就退化成了Single Number， 直接遍历数组异或即可得到结果
 
 tips:
 1. 使用 原码&补码 可以快速求得第一位出现1的数值 => 6&=-6  （110）& (010) = (010)
 */
class Solution {
    func singleNumber(_ nums: [Int]) -> [Int] {
        var ans = [0 , 0]
        
        var tmp =  nums.reduce(0) { $0^$1 }
        
        tmp &= -tmp
        
        for num in nums {
            if tmp & num == 0 {
                ans[0] = ans[0] ^ num
            } else {
                ans[1] = ans[1] ^ num
            }
        }
        
        
        return ans
    }
}

