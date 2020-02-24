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


// 25 / 25 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// Memory Usage: 9.9 MB
class Solution {
  public:
	string largestMultipleOfThree(vector<int> &ds) {
		int sum = accumulate(ds.begin(), ds.end(), 0);
		vector<int> digitCnt(10, 0);
		for (auto it : ds)
			digitCnt[it]++;

		auto buildAnsStr = [&](void) {
			string ans = "";
			for (int i = 9; i > 0; --i)
				for (int j = 0; j < digitCnt[i]; j++)
					ans += to_string(i);
			if (digitCnt[0] > 0) {
				if (ans.length() < 1)
					return to_string(0);
				for (int i = 0; i < digitCnt[0]; i++)
					ans += "0";
			}
			return ans;
		};

		auto removeIfCan = [&](vector<int> nums, int needRemove) {
			for (auto i : nums) {
				int minCnt = min(digitCnt[i], needRemove);
				digitCnt[i] -= minCnt;
				needRemove -= minCnt;
				if (!needRemove)
					break;
			}
			return needRemove == 0;
		};

		switch (sum % 3) {
			case 1:
				if (removeIfCan({1, 4, 7}, 1) || removeIfCan({2, 5, 8}, 2)) {
					return buildAnsStr();
				}
				break;
			case 2:
				if (removeIfCan({2, 5, 8}, 1) || removeIfCan({1, 4, 7}, 2)) {
					return buildAnsStr();
				}
				break;
		}

		return buildAnsStr();
	}
};

int main() {
	Solution solve;
	string ans;
#define TEST(nums, exp)                                                                                                \
	ans = solve.largestMultipleOfThree(nums);                                                                          \
	cout << ans << endl;                                                                                               \
	assert(ans == exp);

	vector<int> ds = {9, 1, 8};
	TEST(ds, "981")
	vector<int> ds1 = {8, 6, 7, 1, 0};
	TEST(ds1, "8760")
	vector<int> ds2 = {1};
	TEST(ds2, "")
	vector<int> ds3 = {0, 0, 0, 0, 0, 0};
	TEST(ds3, "0")
	vector<int> ds4 = {1, 1, 1, 2, 3, 3, 3};
	TEST(ds4, "333111")
	vector<int> ds5 = {2, 2, 0, 8, 8, 8};
	TEST(ds5, "8880")
	vector<int> ds6 = {5, 8};
	TEST(ds6, "")
}
