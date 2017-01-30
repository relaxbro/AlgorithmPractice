#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* gives 342 + 465 = 807
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(0), *p = res;
		int carry = 0;

		while (l1 || l2 || carry)
		{
			if (l1)
			{
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				carry += l2->val;
				l2 = l2->next;
			}
			p->next = new ListNode(carry % 10);
			carry /= 10;
			p = p->next;
		}
		return res->next;
		
	}
};


int main()
{

	cout << endl;
	return 0;
}