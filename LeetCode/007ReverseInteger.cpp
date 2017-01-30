#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
	int reverse(int x)
	{
		int origX = abs(x);
		int reversed = 0;
		int remainder;
		while (origX != 0)
		{
			remainder = origX % 10;
			if (reversed > (INT_MAX - remainder) / 10)
			{
				return 0;
			}
			reversed = 10 * reversed + remainder;
			origX /= 10;
		}
		if (x < 0)
		{
			return -reversed;
		}
		return reversed;
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.reverse(123) << endl;
	cout << sol.reverse(-123) << endl;
	cout << sol.reverse(1534236469) << endl;

	cout << endl;
	return 0;
}