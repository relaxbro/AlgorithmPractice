#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]

*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;

		if (nums.size() < 4) return res;

		sort(nums.begin(), nums.end());

		int n = nums.size();

		for (int i = 0; i < n; i++) {
			int tar3 = target - nums[i];
				for (int j = i + 1; j < n; j++) {
					int tar2 = tar3 - nums[j];
					int front = j + 1;
					int back = n - 1;

					while (front < back) {
						int two = nums[front] + nums[back];
						if (tar2 > two) front++;
						else if (tar2 < two) back--;
						else {
							vector<int> temp(4, 0);
							temp[0] = nums[i];
							temp[1] = nums[j];
							temp[2] = nums[front];
							temp[3] = nums[back];
							res.push_back(temp);

							while (front < back && nums[front] == temp[2]) ++front;
							while (front < back && nums[back] == temp[3]) --back;
						}
					}

					while (j + 1 < n && nums[j + 1] == nums[j]) ++j;
				}

				while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
		}

		return res;
	}
};


int main()
{
	Solution sol = Solution();

	
	cout << endl;
	return 0;
}