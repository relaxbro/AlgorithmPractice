#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>

using namespace std;

/*
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		string sub = "";
		int longest = 0;
		string longestStr = "";

		int counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (sub.find(s[i]) != string::npos)
			{
				sub = sub.substr(sub.find(s[i]) + 1, sub.length() - 1) + s[i];
				counter = sub.length();
			}
			else
			{
				sub += s[i];
				counter++;
				if (counter > longest)
				{
					longest = counter;
					longestStr = sub;
				}
			}
		}

		//cout << longestStr << endl;
		return longest;
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << sol.lengthOfLongestSubstring("aab") << endl;
	cout << sol.lengthOfLongestSubstring("dvdf") << endl;
	cout << sol.lengthOfLongestSubstring("I have a variable of type string. I want to check if it contains a certain string. How would I do that?") << endl;

	cout << endl;
	return 0;
}