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

// 488. Zuma Game

// Think about Zuma Game. You have a row of balls on the table, colored red(R),
// yellow(Y), blue(B), green(G), and white(W). You also have several balls in
// your hand.

// Each time, you may choose a ball in your hand, and insert it into the row
// (including the leftmost place and rightmost place). Then, if there is a group
// of 3 or more balls in the same color touching, remove these balls. Keep doing
// this until no more balls can be removed.

// Find the minimal balls you have to insert to remove all the balls on the
// table. If you cannot remove all the balls, output -1.

// Example 1:

// Input: board = "WRRBBW", hand = "RB"
// Output: -1
// Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
// Example 2:

// Input: board = "WWRRBBWW", hand = "WRBRW"
// Output: 2
// Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
// Example 3:

// Input: board = "G", hand = "GGGGG"
// Output: 2
// Explanation: G -> G[G] -> GG[G] -> empty
// Example 4:

// Input: board = "RBYYBBRRB", hand = "YRBGB"
// Output: 3
// Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] ->
// BB[B] -> empty

// Constraints:

// You may assume that the initial row of balls on the table won’t have any 3 or
// more consecutive balls with the same color. The number of balls on the table
// won't exceed 16, and the string represents these balls is called "board" in
// the input. The number of balls in your hand won't exceed 5, and the string
// represents these balls is called "hand" in the input. Both input strings will
// be non-empty and only contain characters 'R','Y','B','G','W'.
/**
  28 / 28 test cases passed.
  Status: Accepted
  Runtime: 1244 ms
  Memory Usage: 332.4 MB
 */
class Solution {
 public:
  static constexpr int CNT = 5;
  struct state {
    unordered_map<char, int> hand;
    string cur;
    int step;
    state(string board, string h) {
      step = 0;
      cur = board;
      for (auto& c : h) ++hand[c];
    }
    state(string board, unordered_map<char, int> h, int s) {
      cur = board;
      hand = h;
      step = s;
    }
    string stateHashCode() {
      string suffix = "";
      for (auto& it : hand) {
        suffix += string(1, it.first) + to_string(it.second);
      }
      return cur + suffix;
    }
  };
  using State = struct state;
  pair<int, int> isVaild(string cur) {
    for (int i = 0; i < cur.length(); i++) {
      int left = i - 1, right = i + 1, cnt = 1;
      while (left > -1 && cur[left] == cur[i]) --left, ++cnt;
      while (right < cur.length() && cur[right] == cur[i]) ++right, ++cnt;

      if (cnt > 2) {
        return {left + 1, right};
      }
    }
    return {-1, -1};
  }
  string dfs(string cur) {
    pair<int, int> result = isVaild(cur);
    if (result.first == -1) return cur;
    return dfs(cur.substr(0, result.first) +
               cur.substr(result.second, cur.length() - result.second));
  }
  vector<string> zumaInsertHand(string& board, char c) {
    vector<string> ret;
    unordered_map<string, bool> vis;
    for (int i = 0; i < board.length(); ++i) {
      string tmp = board;
      tmp.insert(tmp.begin() + i, c);
      tmp = dfs(tmp);
      // cout<<board<<" insert "<<c<<" at "<<i<<" result: "<<tmp<<endl;
      if (!vis[tmp]) {
        vis[tmp] = true;
        ret.push_back(tmp);
      }
    }
    return ret;
  }

  int bfs(const string& board, const string& hand) {
    queue<State> q;
    q.push({board, hand});
    unordered_map<string, bool> vis;
    vis[q.front().stateHashCode()] = true;
    while (!q.empty()) {
      auto now = q.front();
      q.pop();
      if (now.cur.length() == 0) return now.step;
      for (auto& it : now.hand) {
        if (it.second < 1) continue;
        vector<string> nextBoards = zumaInsertHand(now.cur, it.first);
        for (auto& nextBoard : nextBoards) {
          auto nextHand = now.hand;
          --nextHand[it.first];
          State next = {nextBoard, nextHand, now.step + 1};
          string nextHashCode = next.stateHashCode();
          if (!vis[nextHashCode]) {
            vis[nextHashCode] = true;
            q.push(next);
          }
        }
      }
    }
    return -1;
  }

  int findMinStep(string board, string hand) { return bfs(board, hand); }
};

int main() {
  Solution solve;
  assert(solve.findMinStep("WRRBBW", "RB") == -1);
  assert(solve.findMinStep("WWRRBBWW", "WRBRW") == 2);
  assert(solve.findMinStep("G", "GGGGG") == 2);
  assert(solve.findMinStep("RBYYBBRRB", "YRBGB") == 3);
  assert(solve.findMinStep("", "YRBGB") == 0);
  return 0;
}