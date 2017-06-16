#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/


class Solution {
public:
    bool isValid(string s) {
        int len = s.length();

        if (len == 0 || len % 2 == 1) return false;

        char prev = s[0];
        if (prev == ')' || prev == ']' || prev == '}') return false;

        stack<char> c;
        for (char current : s) {
            if (current == '(' || current == '[' || current == '{') c.push(current);
            else {
                if (c.empty()) return false;
                if (current == ')' && c.top() != '(') return false;
                if (current == ']' && c.top() != '[') return false;
                if (current == '}' && c.top() != '{') return false;
                c.pop();
            }
        }
        return c.empty();
    }
};


int main()
{
    Solution sol = Solution();

    cout << sol.isValid("()") << " true" << endl;
    cout << sol.isValid("(){") << " false" << endl;
    cout << sol.isValid("({)}") << " false" << endl;
    cout << sol.isValid("()[]{}") << " true" << endl;
    cout << sol.isValid("{}{}{}{}{}{}[][][][][]()()()()()") << " true" << endl;
    cout << sol.isValid("([])") << " true" << endl;
    cout << endl;
    return 0;
}