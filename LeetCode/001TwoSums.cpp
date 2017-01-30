#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		map<int, int> map;
		int temp;

		for (int i = 0; i < nums.size(); i++)
		{
			map[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			temp = target - nums[i];
			if (map.find(temp) != map.end() && map[temp] != i)
			{
				result.push_back(i);
				result.push_back(map[temp]);

				return result;
			}
		}

		return result;
	}




	/*
	// Slow double loop implementation O(n^2)
	vector<int> twoSum(vector<int>& nums, int target)
	{
	int length = nums.size();
	vector<int> results;

	for (int i = 0; i < length; i++)
	{
	for (int j = i + 1; j < length; j++)
	{
	if (nums[i] + nums[j] == target)
	{
	results = {i, j};
	return results;
	}
	}
	}
	}
	*/
};


int main()
{
	vector<int> input = { 2, 7, 11, 16 };
	Solution sol = Solution();
	for (auto i : sol.twoSum(input, 9))
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}