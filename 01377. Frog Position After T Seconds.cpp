#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
1377. Frog Position After T Seconds
DescriptionHintsSubmissionsDiscussSolution
Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from
the vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if
they are directly connected. The frog can not jump back to a visited vertex. In case the frog can
jump to several vertices it jumps randomly to one of them with the same probability, otherwise, when
the frog can not jump to any unvisited vertex it jumps forever on the same vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means
that exists an edge connecting directly the vertices fromi and toi.

Return the probability that after t seconds the frog is on the vertex target.
 */

// 203 / 203 test cases passed.
// Status: Accepted
// Runtime: 80 ms
// Memory Usage: 17.3 MB

class Solution {
  public:
	double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
		unordered_map<int, vector<int>> mp;
		for (auto &e : edges) {
			mp[e[0]].push_back(e[1]);
			mp[e[1]].push_back(e[0]);
		}
		vector<bool> vis(n, false);
		queue<tuple<int, int, double>> q;
		q.push({1, 0, 1.0});
		vis[1] = true;
		while (!q.empty()) {
			auto [p, step, prob] = q.front();
			q.pop();

			if (step > t) {
				continue;
			}

			if (p == target && step == t) {
				return prob;
			}

			int nextCnt = 0;
			for (int &next : mp[p]) {
				if (!vis[next])
					++nextCnt;
			}

			if (!nextCnt) {
				q.push({p, step + 1, prob});
				continue;
			}

			for (int next : mp[p]) {
				if (!vis[next]) {
					vis[next] = true;
					q.push({next, step + 1, prob * 1.0 / nextCnt});
				}
			}
		}

		return 0.0;
	}
};

int main() { return 0; }