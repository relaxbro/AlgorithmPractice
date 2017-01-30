#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "a*") -> true
isMatch("aa", ".*") -> true
isMatch("ab", ".*") -> true
isMatch("aab", "c*a*b") -> true
*/

class Solution {
public:
	bool helper(const string &s, int sPos, const string &p, int pPos) {
		int sLen = s.length();
		int pLen = p.length();

		if (pPos == pLen) return (sPos == sLen);
		if (p[pPos + 1] != '*')
		{
			if (sPos < sLen && (p[pPos] == s[sPos] || p[pPos] == '.')) return helper(s, sPos + 1, p, pPos + 1);
		}
		else
		{
			if (helper(s, sPos, p, pPos + 2)) return true;
			while (sPos < sLen && (p[pPos] == s[sPos] || p[pPos] == '.'))
			{
				if (helper(s, ++sPos, p, pPos + 2)) return true;
			}
		}
		return false;
	}

	bool isMatch(string s, string p) {
		return helper(s, 0, p, 0);
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.isMatch("aa", "a") << " 0" << endl;
	cout << sol.isMatch("aa", "aa") << " 1" << endl;
	cout << sol.isMatch("aaa", "aa") << " 0" << endl;
	cout << sol.isMatch("aa", "a*") << " 1" << endl;
	cout << sol.isMatch("aa", ".*") << " 1" << endl;
	cout << sol.isMatch("ab", ".*") << " 1" << endl;
	cout << sol.isMatch("aab", "c*a*b") << " 1" << endl;

	cout << endl;
	return 0;
}