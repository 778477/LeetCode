#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 354. Russian Doll Envelopes

// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into
// another if and only if both the width and height of one envelope is greater than the width and height of the other
// envelope.

// What is the maximum number of envelopes can you Russian doll? (put one inside other)

// Note:
// Rotation is not allowed.

// Example:

// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

// Runtime: 168 ms, faster than 65.29% of C++ online submissions for Russian Doll Envelopes.
// Memory Usage: 48.5 MB, less than 16.67% of C++ online submissions for Russian Doll Envelopes.

class Solution {
  public:
	int maxEnvelopes(vector<vector<int>> &envelopes) {

		sort(envelopes.begin(), envelopes.end(), [](const auto lhs, const auto rhs) {
			if (lhs[0] == rhs[0]) {
				return lhs[1] > rhs[1];
			}
			return lhs[0] < rhs[0];
		});

		vector<int> tmp;
		if (!envelopes.empty())
			tmp.push_back(envelopes[0][1]);

		for (int i = 1; i < envelopes.size(); i++) {
			auto it = lower_bound(tmp.begin(), tmp.end(), envelopes[i][1]);
			if (it == tmp.end()) {
				tmp.push_back(envelopes[i][1]);
			} else {
				tmp[it - tmp.begin()] = envelopes[i][1];
			}
		}

		return tmp.size();
	}
};
