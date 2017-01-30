#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
{-4, -1, 1, 2}
{0, 1, 1, 1} target -100



The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();

		// sort input
		sort(nums.begin(), nums.end());
		int numI, sumTemp, left, right;

		// set first closest value
		int closest = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < len - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			left = i + 1;
			right = len - 1;

			while (left < right)
			{
				sumTemp = nums[i] + nums[left] + nums[right];
				if (sumTemp == target) return target;
				// if current is closer to target, set new closest
				else if (abs(sumTemp - target) < abs(closest - target)) closest = sumTemp;
				// iterate in right direction
				if (sumTemp < target) left++;
				else right--;

			}
		}
		return closest;
	}
};


int main()
{
	//vector<int> trips{ 0, 0, 1, 2 };
	//if (find(trips.begin(), trips.end(), 0) != trips.end() && find(trips.begin(), trips.end(), 0) != trips.end()) cout << "asdfasdfa";
	Solution sol = Solution();
	cout << sol.threeSumClosest(vector<int> {-1, 0, 1, 2, -1, -4}, 3) << " = 3, target = 3" << endl;
	cout << sol.threeSumClosest(vector<int> {-1, 2, 1, -4}, 1) << " = 2, target = 1" << endl;
	cout << sol.threeSumClosest(vector<int> {1, 1, 1, 0}, -100) << " = 2, target = -100" << endl;
	cout << sol.threeSumClosest(vector<int> {-3, 0, 1, 2}, 1) << " = 0, target = 1" << endl;



	cout << endl;
	return 0;
}