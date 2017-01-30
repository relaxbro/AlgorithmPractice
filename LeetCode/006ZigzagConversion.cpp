#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

P     I     N
A   L S   I G
Y A   H R
P     I

convert("PAYPALISHIRING", 4) = "PINALSIGYAHRPI"
*/

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
		{
			return s;
		}

		string newString = "";
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0, k = i; k < s.size(); j++) {
				newString += s[k];
				k += ((i == 0 || (j % 2 == 0)) && (i != numRows - 1)) ? 2 * (numRows - i - 1) : 2 * i;
			}
		}
		return newString;
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.convert("PAYPALISHIRING", 3) << endl;
	cout << sol.convert("PAYPALISHIRING", 4) << endl;
	cout << sol.convert("bgasfdgabad", 5) << endl;
	cout << sol.convert("cbgdsgsdfbd", 2) << endl;
	cout << sol.convert("cfja;sdfanf;asuyfsdlkdaapaad", 4) << endl;


	cout << endl;
	return 0;
}