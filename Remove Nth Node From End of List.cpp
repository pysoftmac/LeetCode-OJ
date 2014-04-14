#include "util.h"
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p, *q;
		q = head;
		for(int i = 0; i < n; i++)
			q = q->next;
		if(q == NULL)
			head = head->next;
		else
		{
			p = head;

			while(q->next != NULL)
			{
				p = p->next;
				q = q->next;
			}
			p->next = p->next->next;
		}
		return head;
    }
};