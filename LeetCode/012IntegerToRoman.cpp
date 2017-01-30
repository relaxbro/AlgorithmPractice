#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

Symbol 	I 	V 	X 	L 	C 	     D      M
Value 	1 	5 	10 	50 	100 	500 	1,000


string M[] = { "","M","MM","MMM" };
string C[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
string X[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
string I[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
ans = M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[(num % 10)];

*/

class Solution {
public:
	string intToRoman(int num) {
		if (num > 3999 || num <= 0) return NULL;
		//string ans = "";
		string M[] = { "","M","MM","MMM" };
		string C[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		string X[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
		string I[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
		return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[(num % 10)];
		//return ans;
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.intToRoman(4) << "  = IV" << endl;
	cout << sol.intToRoman(9) << "  = IX" << endl;
	cout << sol.intToRoman(40) << "  = XL" << endl;
	cout << sol.intToRoman(90) << "  = XC" << endl;
	cout << sol.intToRoman(400) << "  = CD" << endl;
	cout << sol.intToRoman(900) << "  = CM" << endl;
	cout << sol.intToRoman(1954) << "  = MCMLIV" << endl;
	cout << sol.intToRoman(1990) << "  = MCMXC" << endl;
	cout << sol.intToRoman(2014) << "  = MMXIV" << endl;
	cout << sol.intToRoman(3999) << "  = MMMCMXCIX" << endl;


	cout << endl;
	return 0;
}