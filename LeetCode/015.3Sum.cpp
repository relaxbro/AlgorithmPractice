#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]

*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> trips;
		if (nums.size() < 3) return trips;
		int len = nums.size();
		// sort input
		sort(nums.begin(), nums.end());
		int tar, sumTemp, left, right;

		for (int i = 0; i < len; i++)
		{
			tar = nums[i];
			left = i + 1;
			right = len - 1;
			// if target is positive all numbers to the right is also positive
			if (tar > 0) break;

			while (left < right)
			{
				sumTemp = nums[left] + nums[right];
				// less than zero, move to left
				if ((tar + sumTemp) < 0) left++;
				// more than zero, move to right
				else if ((tar + sumTemp) > 0) right--;
				// som is zero, add to results
				else
				{
					trips.push_back(vector<int> {nums[i], nums[left], nums[right]});

					// skip to next number
					while (left < right && nums[left] == trips.back()[1]) left++;
					while (right > left && nums[right] == trips.back()[2]) right--;
				}
			}
			// skip to next i
			while (i + 1 < len && nums[i + 1] == nums[i]) i++;
		}
		return trips;
	}


	// TOO SLOW

	//bool equalsZero(int a, int b, int c)
	//{
	//	if (a + b + c == 0) return true;
	//	return false;
	//}

	//bool contains(vector<vector<int>>& trips, vector<int>& permutation)
	//{
	//	if (trips.size() == 0) return false;

	//	for (int i = 0; i < trips.size(); i++)
	//	{	
	//		if (is_permutation(trips[i].begin(), trips[i].end(), permutation.begin())) return true;

	//		// did not work on the case with 0, 0, 0
	//		/*if ((find(trips[i].begin(), trips[i].end(), a) != trips[i].end()) && (find(trips[i].begin(), trips[i].end(), b) != trips[i].end()) && (find(trips[i].begin(), trips[i].end(), c) != trips[i].end()))
	//		{
	//			return true;
	//		}*/
	//	}
	//	return false;
	//}

	//vector<vector<int>> threeSum(vector<int>& nums) {
	//	vector<vector<int>> trips;
	//	if (nums.size() < 3) return trips;

	//	int len = nums.size();
	//	for (int i = 0; i < len-2; i++)
	//	{
	//		for (int j = i + 1; j < len - 1; j++)
	//		{
	//			for (int k = j + 1; k < len; k++)
	//			{
	//				if (equalsZero(nums[i], nums[j], nums[k]))
	//				{
	//					vector<int> permutation{ nums[i], nums[j], nums[k] };
	//					if (!contains(trips, permutation)) trips.push_back(permutation);
	//				}
	//			}
	//		}
	//	}
	//	return trips;
	//}
};

string printTriplet(vector<vector<int>>& trips)
{
	if (trips.size() == 0) return "";
	string out = "";
	for (int i = 0; i < trips.size(); i++)
	{
		out += "[ ";
		for (int j = 0; j < trips[i].size(); j++)
		{
			out += to_string(trips[i][j]) + " ";
		}
		out += "], ";
	}
	return out;
}


int main()
{
	//vector<int> trips{ 0, 0, 1, 2 };
	//if (find(trips.begin(), trips.end(), 0) != trips.end() && find(trips.begin(), trips.end(), 0) != trips.end()) cout << "asdfasdfa";
	Solution sol = Solution();
	cout << printTriplet(sol.threeSum(vector<int> {-1, 0, 1, 2, -1, -4})) << " = [-1, 0, 1], [-1, -1, 2]" << endl;
	cout << printTriplet(sol.threeSum(vector<int> {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0})) << " = [-5,1,4],[-4,0,4],[-4,1,3],[-2,-2,4],[-2,1,1],[0,0,0]" << endl;
	cout << printTriplet(sol.threeSum(vector<int> {-13, 11, 11, 0, -5, -14, 12, -11, -11, -14, -3, 0, -3, 12, -1, -9, -5, -13, 9, -7, -2, 9, -1, 4, -6, -13, -7, 10, 10, 9, 7, 13, 5, 4, -2, 7, 5, -13, 11, 10, -12, -14, -5, -8, 13, 2, -2, -14, 4, -8, -6, -13, 9, 8, 6, 10, 2, 6, 5, -10, 0, -11, -12, 12, 8, -7, -4, -9, -13, -7, 8, 12, -14, 10, -10, 14, -3, 3, -15, -14, 3, -14, 10, -11, 1, 1, 14, -11, 14, 4, -6, -1, 0, -11, -12, -14, -11, 0, 14, -9, 0, 7, -12, 1, -6})) << endl;


	cout << endl;
	return 0;
}