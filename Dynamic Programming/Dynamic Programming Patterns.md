---
layout: post
title:  "Dynamic Programming Patterns"
date:   2020-10-10 15:05:26 +0800
categories: algo
---


[Dynamic Programming Patterns](https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns/714716)


动态规划一直是我的短板，正好有帖子谈论动态规划题型。这里做一下集中练习和思考。

## 模式 & 范式

题主总结了几种动态规划的模式。这里的模式指的是背后的状态转移方程相似，可以归为一类细化的题型。
在比赛中识别出题意背后的"模式"很重要，可以加快解题速度。

1. Minimum (Maximum) Path to Reach a Target
2. Distinct Ways
3. Merging Intervals
4. DP on Strings
5. Decision Making


这里遵从题主的原意，没有做翻译。其实我也没有想到什么好的翻译。


### Minimum (Maximum) Path to Reach a Target

|题目|难度|状态|
|:--:|:--:|:--:|
|[746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)|Easy|[DONE](https://leetcode.com/submissions/detail/406876795/)|
|[64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)|Medium|[DONE](https://leetcode.com/submissions/detail/406879499/)|
|[322. Coin Change](https://leetcode.com/problems/coin-change/)|Medium|[DONE](https://leetcode.com/submissions/detail/406882568/)|
|[931. Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/)|Medium|[DONE](https://leetcode.com/submissions/detail/406888641/)|
|[983. Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)|Medium||
|[650. 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/)|Medium||
|[279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)|Medium||
|[1049. Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/)|Medium||
|[120. Triangle](https://leetcode.com/problems/triangle/)|Medium||
|[474. Ones and Zeroes ](https://leetcode.com/problems/ones-and-zeroes/)|Medium||
|[221. Maximal Square](https://leetcode.com/problems/maximal-square/)|Medium||
|[1240. Tiling a Rectangle with the Fewest Squares](https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/)|Hard||
|[174. Dungeon Game ](https://leetcode.com/problems/dungeon-game/)|Hard||
|[871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/)|Hard||
