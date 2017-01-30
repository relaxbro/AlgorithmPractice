#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.

*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		int indexOfShortest = findShortestEntry(strs);
		string prefix = strs[indexOfShortest];

		bool done = false;
		while (!done)
		{
			for (int i = 0; i < strs.size(); i++)
			{
				if (prefix != strs[i].substr(0, prefix.length()))
				{
					done = false;
					prefix = prefix.substr(0, prefix.length() - 1);
					break;
				}
				done = true;
			}
		}
		return prefix;
	}

	int findShortestEntry(vector<string>& strs) {
		int shortest = 0;
		for (int i = 1; i < strs.size(); i++)
		{
			if (strs[i].length() < strs[shortest].length())
			{
				shortest = i;
			}
		}
		return shortest;
	}

	bool stringContainsPrefix(string str, string prefix)
	{
		if (prefix == str.substr(0, prefix.length())) return true;
		return false;
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.longestCommonPrefix(vector<string> {"aids", "aid", "aiisfantastic"}) << "  = ai" << endl;
	cout << sol.longestCommonPrefix(vector<string> {"abcd", "aid", "abc"}) << "  = a" << endl;
	cout << sol.longestCommonPrefix(vector<string> {}) << "  = " << endl;

	cout << endl;
	return 0;
}