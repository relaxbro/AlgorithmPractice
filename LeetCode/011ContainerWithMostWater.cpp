#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int area = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right)
		{
			// area is max of previous or new
			area = max(area, (right - left) * min(height[left], height[right]));
			// move left or right according to smallest height
			(height[left] > height[right]) ? right-- : left++;
		}
		return area;
	}

};


int main()
{
	Solution sol = Solution();
	cout << sol.maxArea(vector<int> { 1, 1 }) << "  = 1" << endl;
	cout << sol.maxArea(vector<int> { 1, 2, 1 }) << "  = 2" << endl;


	cout << endl;
	return 0;
}