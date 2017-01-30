#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

Subscribe to see which companies asked this question
*/

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0) && x > 0) return false;
		if (x == 0) return true;
		int i = 0;
		while (i < x) {
			i = i * 10 + x % 10;
			x /= 10;
		}
		return (i == x || i / 10 == x);
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.isPalindrome(0) << endl;
	cout << sol.isPalindrome(11311) << endl;
	cout << sol.isPalindrome(-11311) << endl;
	cout << sol.isPalindrome(INT_MAX) << endl;

	cout << endl;
	return 0;
}