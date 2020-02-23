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

// 1363. Largest Multiple of Three

// Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of
// the given digits in any order.

// Since the answer may not fit in an integer data type, return the answer as a string.

// If there is no answer return an empty string.

// Example 1:

// Input: digits = [8,1,9]
// Output: "981"
// Example 2:

// Input: digits = [8,6,7,1,0]
// Output: "8760"
// Example 3:

// Input: digits = [1]
// Output: ""
// Example 4:

// Input: digits = [0,0,0,0,0,0]
// Output: "0"

// Constraints:

// 1 <= digits.length <= 10^4
// 0 <= digits[i] <= 9
// The returning answer must not contain unnecessary leading zeros.

class Solution {
  public:
	string creatNumberString(vector<int> &ds) {
		string ans = "";
		if (ds.empty())
			return ans;
		for (auto i : ds) {
			if (i == 0 && ans.length() == 0)
				continue;
			ans += to_string(i);
		}
		return ans.length() == 0 ? "0" : ans;
	}

	string largestMultipleOfThree(vector<int> &ds) {
		sort(ds.begin(), ds.end(), greater<int>());
		int sum = accumulate(ds.begin(), ds.end(), 0);
		string ans = "";
		if (sum % 3 == 0) {
			return creatNumberString(ds);
		}

		vector<vector<pair<int, int>>> mod(3, vector<pair<int, int>>());
		for (int i = 0; i < ds.size(); i++) {
			if (ds[i] % 3 == 0)
				continue;
			mod[ds[i] % 3].push_back({i, ds[i]});
		}

		sort(mod[1].begin(), mod[1].end(), [](const auto lhs, const auto rhs) { return lhs.second < rhs.second; });
		sort(mod[2].begin(), mod[2].end(), [](const auto lhs, const auto rhs) { return lhs.second < rhs.second; });

		if (sum % 3 == 1) {
			// 优先考虑移除一个最小 mod%3 == 1 的数
			if (!mod[1].empty()) {
				ds.erase(ds.begin() + mod[1].front().first);
				return creatNumberString(ds);
			}
			// 其次考虑移除两个最小 mod%3 == 2 的数
			vector<int> evenIndexs;
			for (int i = 0; i < mod[2].size(); i++) {
				evenIndexs.push_back(mod[2][i].first);
				if (evenIndexs.size() == 2)
					break;
			}

			if (evenIndexs.size() == 2) {
				if (evenIndexs[0] > evenIndexs[1]) {
					swap(evenIndexs[0], evenIndexs[1]);
				}
				ds.erase(ds.begin() + evenIndexs[1]);
				ds.erase(ds.begin() + evenIndexs[0]);
				return creatNumberString(ds);
			}
		} else if (sum % 3 == 2) {
			// 优先考虑移除一个最小 mod%3 == 2 的数
			if (!mod[2].empty()) {
				ds.erase(ds.begin() + mod[2].front().first);
				return creatNumberString(ds);
			}

			vector<int> oddIndexs;
			for (int i = 0; i < mod[1].size(); i++) {
				oddIndexs.push_back(mod[1][i].first);
				if (oddIndexs.size() == 2)
					break;
			}
			// 其次考虑移除两个最小 mod%3 == 1 的数
			if (oddIndexs.size() == 2) {
				if (oddIndexs[0] > oddIndexs[1]) {
					swap(oddIndexs[0], oddIndexs[1]);
				}
				ds.erase(ds.begin() + oddIndexs[1]);
				ds.erase(ds.begin() + oddIndexs[0]);
				return creatNumberString(ds);
			}
		}
		return "";
	}
};

int main() {
	Solution solve;
	vector<int> ds = {9, 1, 8};
	assert(solve.largestMultipleOfThree(ds) == "981");
	vector<int> ds1 = {8, 6, 7, 1, 0};
	assert(solve.largestMultipleOfThree(ds1) == "8760");
	vector<int> ds2 = {1};
	assert(solve.largestMultipleOfThree(ds2) == "");
	vector<int> ds3 = {0, 0, 0, 0, 0, 0};
	assert(solve.largestMultipleOfThree(ds3) == "0");
	vector<int> ds4 = {1, 1, 1, 2, 3, 3, 3};
	assert(solve.largestMultipleOfThree(ds4) == "333111");
	vector<int> ds5 = {2, 2, 0, 8, 8, 8};
	assert(solve.largestMultipleOfThree(ds5) == "8880");
	vector<int> ds6 = {5, 8};
	assert(solve.largestMultipleOfThree(ds6) == "");
}
