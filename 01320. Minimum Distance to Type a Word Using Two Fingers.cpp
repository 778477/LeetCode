#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 *
1320. Minimum Distance to Type a Word Using Two Fingers

You have a keyboard layout as shown above in the XY plane, where each English
uppercase letter is located at some coordinate, for example, the letter A is
located at coordinate (0,0), the letter B is located at coordinate (0,1), the
letter P is located at coordinate (2,3) and the letter Z is located at
coordinate (4,1).

Given the string word, return the minimum total distance to type such string
using only two fingers. The distance between coordinates (x1,y1) and (x2,y2) is
|x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so don't
count towards your total distance, also your two fingers do not have to start at
the first letter or the first two letters.



Example 1:

Input: word = "CAKE"
Output: 3
Explanation:
Using two fingers, one optimal way to type "CAKE" is:
Finger 1 on letter 'C' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2
Finger 2 on letter 'K' -> cost = 0
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1
Total distance = 3
Example 2:

Input: word = "HAPPY"
Output: 6
Explanation:
Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
Example 3:

Input: word = "NEW"
Output: 3
Example 4:

Input: word = "YEAR"
Output: 7


Constraints:

2 <= word.length <= 300
Each word[i] is an English uppercase letter.

 **/


//  Accepted	
//  264 ms	
//  114.6 MB

class Solution {
 public:
  int minimumDistance(string word) {
    vector<vector<vector<int>>> dp(
        301, vector<vector<int>>(27, vector<int>(27, INT_MAX / 2)));
    constexpr int kRest = 26;
    dp[0][kRest][kRest] = 0;
    int n = word.length();
    auto cost = [](const int from, const int to) {
      if (from == kRest) return 0;
      return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    };
    for (int i = 1; i <= n; i++) {
      int c = word[i - 1] - 'A';
      for (int l = 0; l < 27; l++) {
        for (int r = 0; r < 27; r++) {
          dp[i][c][r] = min(dp[i - 1][l][r] + cost(l, c), dp[i][c][r]);
          dp[i][l][c] = min(dp[i - 1][l][r] + cost(r, c), dp[i][l][c]);
        }
      }
    }

    int ans = INT_MAX;
    for (int l = 0; l < 27; ++l) {
      for (int r = 0; r < 27; ++r) {
        ans = min(ans, dp[n][l][r]);
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  cout << solve.minimumDistance("CAKE") << endl;
  cout << solve.minimumDistance("HAPPY") << endl;
  return 0;
}