#include "util.h"


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* newHead = new ListNode(0);
		newHead->next = head;

		ListNode* prev = newHead;
		for(int i = 0; i < m - 1; i++)
			prev = prev->next;
		ListNode* p = prev->next, *q;

		for(int i = 0; i < n - m; i++)
		{
			q = p->next;
			p->next = q->next;
			q->next = prev->next;
			prev->next = q;
		}

		return newHead->next;
    }
};