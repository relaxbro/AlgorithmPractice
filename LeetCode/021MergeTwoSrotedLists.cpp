#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* head;

        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }

        ListNode* temp = head;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1) temp->next = l1;
        else temp->next = l2;

        return head;
    }
};


int main()
{
    Solution sol = Solution();

    cout << endl;
    return 0;
}