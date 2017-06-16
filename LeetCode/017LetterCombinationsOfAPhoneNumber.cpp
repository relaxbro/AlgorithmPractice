#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;

		if (digits.empty()) return res;

		static const vector<string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		res.push_back("");
		for (int i = 0; i < digits.size(); ++i) {
			int num = digits[i] - '0';
			if (num < 0 || num > 9) break;
			const string& candidate = letters[num];
			if (candidate.empty()) continue;
			vector<string> temp;
			for (int j = 0; j < candidate.size(); ++j) {
				for (int k = 0; k < res.size(); ++k) {
					temp.push_back(res[k] + candidate[j]);
				}
			}
			res.swap(temp);
		}

		return res;
	}
};


int main()
{
	Solution sol = Solution();
	vector<string> res = sol.letterCombinations("23");
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}

	
	cout << endl;
	return 0;
}