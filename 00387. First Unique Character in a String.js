/**

387. First Unique Character in a String 

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.

*/

/** 
  104 / 104 test cases passed.
  Status: Accepted
  Runtime: 242 ms
*/
var firstUniqChar = function(s) {
    for(let i = 0; i<s.length;i++){
      let flag = false;
      for(let j = 0;j<s.length;j++){
        if(i != j && s.charAt(i) === s.charAt(j)){
          flag = true;
          break;
        }
      }

      if(!flag) return i;
    }

    return -1;
};

console.log(firstUniqChar("loveleetcode"))