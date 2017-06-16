#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		if (head->next == NULL) return NULL;

		ListNode *front = head;
		ListNode *back = head;
		while (front != NULL) {
			front = front->next;
			if (n-- < 0) back = back->next;
		}
		if (n == 0) head = head->next;
		else back->next = back->next->next;

		return head;
	}
};


int main()
{
	Solution sol = Solution();

	
	cout << endl;
	return 0;
}