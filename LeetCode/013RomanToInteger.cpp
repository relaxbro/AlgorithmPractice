#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given a roman numeral, convert it to an integer.

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
	int romanToInt(string s) {
		int ans = 0;

		if (s.find("IV") != string::npos) s.replace(s.find("IV"), 2, "IIII");
		if (s.find("IX") != string::npos) s.replace(s.find("IX"), 2, "VIIII");
		if (s.find("XL") != string::npos) s.replace(s.find("XL"), 2, "XXXX");
		if (s.find("XC") != string::npos) s.replace(s.find("XC"), 2, "LXXXX");
		if (s.find("CD") != string::npos) s.replace(s.find("CD"), 2, "CCCC");
		if (s.find("CM") != string::npos) s.replace(s.find("CM"), 2, "DCCCC");
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'I') ans += 1;
			else if (s[i] == 'V') ans += 5;
			else if (s[i] == 'X') ans += 10;
			else if (s[i] == 'L') ans += 50;
			else if (s[i] == 'C') ans += 100;
			else if (s[i] == 'D') ans += 500;
			else if (s[i] == 'M') ans += 1000;
		}
		return ans;
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.romanToInt("II") << "  = 2" << endl;
	cout << sol.romanToInt("IV") << "  = 4" << endl;
	cout << sol.romanToInt("IX") << "  = 9" << endl;
	cout << sol.romanToInt("XL") << "  = 40" << endl;
	cout << sol.romanToInt("XC") << "  = 90" << endl;
	cout << sol.romanToInt("CD") << "  = 400" << endl;
	cout << sol.romanToInt("CM") << "  = 900" << endl;
	cout << sol.romanToInt("MCMLIV") << "  = 1954" << endl;
	cout << sol.romanToInt("MCMXC") << "  = 1990" << endl;
	cout << sol.romanToInt("MMXIV") << "  = 2014" << endl;
	cout << sol.romanToInt("MMMCMXCIX") << "  = 3999" << endl;


	cout << endl;
	return 0;
}