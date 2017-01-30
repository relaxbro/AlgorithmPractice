#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
	bool checkPalindrome(string s)
	{
		//return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
		return equal(s.begin(), s.end(), s.rbegin(), s.rend());
	}

	string helper(string a, string b)
	{
		if (a.size() > b.size())
		{
			return a;
		}
		return b;
	}

	string getPalindromeAt(string s, int l, int u)
	{
		while (l >= 0 && u < s.length() && s[l] == s[u])
		{
			u++;
			l--;
		}
		return s.substr(l + 1, u - l - 1);
	}

	string getPalindromeAt(string s, int i)
	{
		string even = getPalindromeAt(s, i, i + 1);
		string odd = getPalindromeAt(s, i - 1, i + 1);
		return helper(even, odd);
	}

	string longestPalindrome(string s) {
		int len = s.length();
		if (len < 2)
		{
			return s;
		}
		string longest = "";

		for (int i = 0; i < len; i++)
		{
			longest = helper(longest, getPalindromeAt(s, i));
		}
		return longest;
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.longestPalindrome("abb") << endl;
	cout << sol.longestPalindrome("babad") << endl;
	cout << sol.longestPalindrome("cbbd") << endl;
	cout << sol.longestPalindrome("cfja;sdfanf;asuyfsdlkdaapaad") << endl;


	cout << endl;
	return 0;
}