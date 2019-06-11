[1044. Longest Duplicate Substring](https://leetcode.com/problems/longest-duplicate-substring/description/)


## Rabin-Karp


`Rabin-Karp`是一种字符串搜索算法，基于哈希在匹配串中查找模式串。对于长度为`n`的匹配串和长度为`m`的模式串来讲，该算法的最优运行时间是`O(n+m)`



```
function RabinKarp(string s[1..n], string pattern[1..m])
  hpattern := hash(pattern[1..m]);
  for i from 1 to n-m+1
    hs := hash(s[i..i+m-1])
    if hs = hpattern
      if s[i..i+m-1] = pattern[1..m]
        return i
  return not found
```

这里算法的技巧是支持`rolling hash`，这使的下一个hash值可基于上一个hash值计算产生。减少了重复计算量。

```
s[i+1..i+m] = s[i..i+m-1] - s[i] + s[i+m]
```


算法的关键在于你的哈希实现，[Rabin_fingerprint](https://en.wikipedia.org/wiki/Rabin_fingerprint)是一种主流的`rolling hash`方法


## Suffix Array
[Suffix Array](https://www.geeksforgeeks.org/%C2%AD%C2%ADkasais-algorithm-for-construction-of-lcp-array-from-suffix-array/)

> [Ranbin-Karp Algorithm](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)

> [Rabin-Karp Algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)