#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	double medianOfTwo(int a, int b)
	{
		return (double)(a + b) / 2.0;
	}

	double medianOfThree(int a, int b, int c)
	{
		int Max = max(a, max(b, c));
		int Min = min(a, min(b, c));
		return (double)a + b + c - Min - Max;
	}

	double medianOfFour(int a, int b, int c, int d)
	{
		int Max = max(a, max(b, max(c, d)));
		int Min = min(a, min(b, min(c, d)));
		return (double)(a + b + c + d - Min - Max) / 2.0;
	}

	double findMedianOfSortedArray(vector<int>& nums, int len)
	{
		if (len % 2 == 0)
		{
			return (double)(nums[len / 2 - 1] + nums[len / 2]) / 2.0;
		}
		return (double)nums[len / 2];
	}

	double findMedianSortedArraysShortestFirst(vector<int>& nums1, int len1, vector<int>& nums2, int len2)
	{
		// first array is empty, find median of second
		if (len1 == 0)
		{
			return findMedianOfSortedArray(nums2, len2);
		}

		// first array har length 1
		if (len1 == 1)
		{
			// second array also of length 1
			if (len2 == 1)
			{
				return medianOfTwo(nums1[0], nums2[0]);
			}
			// second array length is even
			if (len2 % 2 == 0)
			{
				if (nums1[0] < nums2[len2 / 2 - 1])
				{
					return (double)nums2[len2 / 2 - 1];
				}
				if (nums1[0] > nums2[len2 / 2])
				{
					return (double)nums2[len2 / 2];
				}
				return (double)nums1[0];
			}
			// secoond array length is odd
			if (len2 % 2 != 0)
			{
				if (nums1[0] < nums2[len2 / 2 - 1])
				{
					return medianOfTwo(nums2[len2 / 2 - 1], nums2[len2 / 2]);
				}
				if (nums1[0] > nums2[len2 / 2 + 1])
				{
					return medianOfTwo(nums2[len2 / 2], nums2[len2 / 2 + 1]);
				}
				return medianOfTwo(nums1[0], nums2[len2 / 2]);
			}
		}
		// first array has length 2
		if (len1 == 2)
		{
			// second array also length 2
			if (len2 == 2)
			{
				return medianOfFour(nums1[0], nums1[1], nums2[0], nums2[1]);
			}
			// second array length is even
			if (len2 % 2 == 0)
			{
				return medianOfFour(nums2[len2 / 2 - 1], nums2[len2 / 2], max(nums1[0], nums2[len2 / 2 - 2]), min(nums1[1], nums2[len2 / 2 + 1]));
			}
			// sencond array lenght is odd
			if (len2 % 2 != 0)
			{
				return medianOfThree(nums2[len2 / 2], max(nums1[0], nums2[len2 / 2 - 1]), max(nums1[1], nums2[len2 / 2 + 1]));
			}
		}

		// booth arrays are longer than 2
		int idx1 = (len1 - 1) / 2;
		int idx2 = (len2 - 1) / 2;

		//	/* if A[idxA] <= B[idxB], then median must exist in
		//	A[idxA....] and B[....idxB] */
		//  if (nums1[idx1] <= nums2[idx2])


		//	/* if A[idxA] > B[idxB], then median must exist in
		//	A[...idxA] and B[idxB....] */
		//	return findMedianSortedArraysShortestFirst(nums1, nums2 + idxA, len1 / 2 + 1, len2 - idxA);


	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();

		if (len1 <= len2)
		{
			return findMedianSortedArraysShortestFirst(nums1, len1, nums2, len2);
		}
		else
		{
			return findMedianSortedArraysShortestFirst(nums2, len2, nums1, len1);
		}
	}
};


int main()
{
	Solution sol = Solution();
	cout << sol.findMedianSortedArrays(vector<int> {}, vector<int> {4, 6, 8}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {2}, vector<int> {4, 6, 8}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {5}, vector<int> {4, 6, 8}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {7}, vector<int> {4, 6, 8}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {9}, vector<int> {4, 6, 8}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {}, vector<int> {4, 6, 8, 10}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {2}, vector<int> {4, 6, 8, 10}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {7}, vector<int> {4, 6, 8, 10}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {9}, vector<int> {4, 6, 8, 10}) << endl;
	cout << sol.findMedianSortedArrays(vector<int> {11}, vector<int> {4, 6, 8, 10}) << endl;

	cout << sol.findMedianSortedArrays(vector<int> {1, 2}, vector<int> {3, 4}) << endl;

	cout << sol.findMedianSortedArrays(vector<int> {3, 4, 5, 11}, vector<int> {4, 6, 8, 10}) << endl;



	cout << endl;
	return 0;
}